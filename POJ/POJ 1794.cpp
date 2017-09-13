#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#define maxn 500005
using namespace std;
int n,m;
long long c[2][maxn];
struct P{
	int col,id,val;
	bool operator < (const P& oth)const{
		return id < oth.id;
	}
}p[maxn];
void update(int pos,int who){
	while(pos<maxn){
		c[who][pos]++;
		pos+=pos&(-pos);
	}
}
long long qry(int pos,int who){
 	long long ans = 0;
	while(pos > 0){
		ans += c[who][pos];
		pos -= pos&(-pos);
	}
	return ans;
}
int main(){
	int T,kase = 0;
	scanf("%d",&T);
	while (T--){
		memset(c,0,sizeof(c));
		scanf("%d%d",&n,&m);
		for(int i = 1; i <= n; i++){
			int x,y;
			scanf("%d%d",&x,&y);
			p[i].id = x, p[i].val = y;p[i].col = 0;
		}
		for(int i = 1+n; i <= m+n; i++){
			int x,y;
			scanf("%d%d",&x,&y);
			p[i].id = x, p[i].val = y;p[i].col = 1;
		}
		sort(p+1,p+n+m+1);
		long long  ans = 0;
		for(int i = 1; i <= n + m; i++){
			update(maxn-1-p[i].val,p[i].col);
			ans += qry(maxn-1-p[i].val,!p[i].col);
		}
		printf("Scenario #%d:\n%lld\n\n",++kase,ans);
	}
}