#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD=1e9+7;
const int maxn=1e5+50;
vector<int>G[maxn];
int col[maxn];
int vis[maxn];
int n,m,x,y;
int flag=0;
void dfs(int u,int fa,int co)
{
//    cout<<u<<' '<<fa<<' '<<co<<endl;
    if(flag)return;
    col[u]=co;
 //   vis[u]=1;
    for(auto&v:G[u])
    {
        if(v==fa)continue;

        if(col[v]==col[u]){flag=1;return;}
        if(col[v]!=-1)continue;
        dfs(v,u,!co);
    }
}
int main()
{
    while(scanf("%d%d%d%d",&n,&m,&x,&y)==4)
    {
        memset(vis,0,sizeof(vis));
        memset(col,-1,sizeof(col));
        for(int i=0;i<=n;i++)G[i].clear();
        flag=0;
        int u,v;
        for(int i=0;i<m;i++)
        {
            scanf("%d%d",&u,&v);
            vis[u]=vis[v]=1;
            G[u].push_back(v);
            G[v].push_back(u);
        }
        for(int i=0,a;i<x;i++)
        {
            scanf("%d",&a);vis[a]=1;
            col[x]=1;
            dfs(x,-1,1);
        }
        for(int i=0,x;i<y;i++)
        {
            scanf("%d",&x);vis[x]=1;
            col[x]=0;
            dfs(x,-1,0);
        }
        for(int i=1;i<=n;i++)if(!vis[i])flag=1;
        for(int i=1;i<=n;i++)
        {
            if(col[i]==-1)
                dfs(i,-1,1);
        }
        if(flag)printf("NO\n");
        else printf("YES\n");
    }
}