
#include<bits/stdc++.h>
using namespace std;


const int N = 1e5+5;
typedef long long ll;

ll dp[N][2];
int a[N];
ll dfs(int pos ,int pre, int limit)
{
    if(pos < 0)return 1;
    if(!limit && dp[pos][pre] != -1)
        return dp[pos][pre];
    int end = (limit)? a[pos]:1;
    ll ans = 0;
    for(int i=0;i<=end;++i){
        if(pre == 1 && i == 1)continue;
        else ans += dfs(pos-1,i,limit && (i==end));
    }
    if(!limit) return dp[pos][pre] = ans;
    return ans ;
}

int main()
{
    ll n,i;
    while(scanf("%lld",&n)==1)
    {
        memset(a,0,sizeof(a));
        memset(dp,-1,sizeof(dp));
        int cnt = 0;
	    while(n)
       {
		a[cnt++] = n % 2;
		n /= 2;
	   }
	//   printf("%d\n",cnt);
	   ll ans=dfs(cnt-1,0,1);
	   printf("%lld\n",ans);
    }
}
