#include<bits/stdc++.h>

using namespace std;
const int maxn=105;
vector<int>G[maxn];
int v[100];
int rua[105];
int M[maxn][maxn];
int pos=0;
int ans=0;
int n,m,s;
void dfs(int u,int cnt,int fa,int maxi)
{
 //   cout<<u<<' '<<cnt<<' '<<fa<<endl;


    if(cnt==1)
    {
    //    for(int i=0;i<pos;i++)
    //        cout<<v[i]<<' ';
    //   cout<<u<<endl;
        ans++;return;
    }
    v[pos++]=u;
    for(auto &v:G[u])
    {
   //     cout<<"RUA "<<v<<endl;
        if(v==fa)continue;
        if(v<maxi)continue;
        if(rua[v]<s-1)continue;
        int flag=0;
        for(int i=0;i<pos;i++)
            if(!M[v][::v[i]])
            {
                flag=1;break;
            }
        if(flag)continue;
        dfs(v,cnt-1,u,v);

    }
     pos--;
}
int main()
{
    int T;cin>>T;while(T--)
    {
        ans=0;
        scanf("%d%d%d",&n,&m,&s);
        memset(M,0,sizeof(M));
        for(int i=1;i<=n;i++)G[i].clear(),rua[i]=0;
        int u,v;
        while(m--)
        {
            scanf("%d%d",&u,&v);
            if(u>v)swap(u,v);
            G[u].push_back(v);
            G[v].push_back(u);
            M[u][v]=1;
            M[v][u]=1;
            rua[u]++;
            rua[v]++;
        }
        for(int i=1;i<=n;i++)sort(G[i].begin(),G[i].end());
        for(int i=1;i<=n-s+1;i++)
        {
            pos=0;
            dfs(i,s,-1,i);
       //     for(int j=i+1;j<=n;j++)
        //        G[j].erase(i);
        }
        printf("%d\n",ans);
    }
}