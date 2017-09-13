#include <iostream>
#include<vector>
#include<cstdio>
#include<cstring>
using namespace std;
#define maxn 205
vector<int> G[maxn];
int n, m;
int dp[2][maxn],vis[maxn];
int a[maxn], dif[maxn];
int abs(int a)
{
	if(a<0)return -a;
	return a;
}
void dfs(int v,int p)
{
    vis[v]=1;
    for(int i=0;i<G[v].size();i++)
    {
		int t=G[v][i];
        if(G[v][i]==p)
			continue;
		dfs(t,v);
		dp[1][v]+=dp[0][t];
		dp[0][v]+=max(dp[0][t],dp[1][t]);
    }
}
int main()
{
    while (scanf("%d%d", &n, &m) == 2&&n+m)
    {
		for(int i=0;i<maxn;i++)
			G[i].clear();
        memset(dp,0,sizeof(dp));
        memset(vis,0,sizeof(vis));
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &a[i]);
            dp[1][i] = a[i];
        }
        for (int i = 1; i <= m; i++)
            scanf("%d", &dif[i]);
        for (int i = 1; i <= n; i++)
            for (int j = i + 1; j <= n; j++)
                for (int k = 1; k <= m; k++)
                    if (abs(a[i] - a[j]) == dif[k])
                    {
                        G[i].push_back(j);
                        G[j].push_back(i);
                    }
        int ans=0;
        for (int i = 1; i <= n; i++)
            if (!vis[i])
            {
                dfs(i, -1);
                ans += max(dp[0][i], dp[1][i]);
            }
		printf("%d\n",ans);
    }
}