#include<bits/stdc++.h>
#include<stdlib.h>
using namespace std;
int n, k;
set <int> G[100005];
int vis[100005];
int bfs(int n)
{
    while (!G[n].empty())
    {
        int t=*(G[n].begin());
   //    printf("%d %d\n",t,n);

        G[n].erase(t);
        if(t==k)return n;
        else if(vis[t])continue;
        else
        {
            if(t>=1&&!vis[t-1])G[n+1].insert(t-1);
            if(t<=k&&!vis[t+1])G[n+1].insert(t+1);
            if((t*2<(k+20))&&!vis[t*2])G[n+1].insert(t*2);
        }
 vis[t]=1;
    }
 //   system("pause");
    bfs(n+1);
}
void ini(int n)
{
    memset(vis,0,sizeof(vis));
    for(int i=0;i<n;i++)
        G[n].clear();
}
int main()
{

	while(cin >> n >> k){
    ini(100005);
	G[0].insert(n);
	if(n>k)printf("%d\n",n-k);
	else
	printf("%d\n",bfs(0));
}
return 0;
}
