#include <bits/stdc++.h>
using namespace std;
const int N=8;
double r,sum[1<<N];
int n,w[100],T,vis[1<<N];
struct node{
    double l,r;
    int ls,rs;
    node(double ll=0,double rr=0){l=ll,r=rr;}
};
vector<node>v[1<<N];
void dfs(int subset)
{//printf("dfs %d\n",subset);
    if(vis[subset]) return;
    vis[subset]=1;
    int child=0;
    for(int left=(subset-1)&subset;left;left=(left-1)&subset){
        child=1;
        int right=left^subset;
        dfs(left);dfs(right);

        double dl=sum[right]/sum[subset],dr=sum[left]/sum[subset];
        for(int i=0;i<v[left].size();i++)
            for(int j=0;j<v[right].size();j++){
                node t;
                t.l=max(v[left][i].l+dl,v[right][j].l-dr);
                t.r=max(v[left][i].r-dl,v[right][j].r+dr);
                if(t.l+t.r<r) v[subset].push_back(t);
            }
    }
    if(!child) v[subset].push_back(node());
}
int main()
{

    int argc;
    const char *argv[N];
    scanf("%d",&T);
    while(T--)
        {
        scanf("%lf%d",&r,&n);
        for(int i=0;i<n;i++) scanf("%d",&w[i]);
        for(int i=0;i<(1<<n);i++)
            {
            sum[i]=vis[i]=0;
            v[i].clear();
            for(int j=0;j<n;j++) if(i&(1<<j)) sum[i]+=w[j];
        }
        //for(int i=0;i<(1<<n);i++) printf("sum %d\n",sum[i]);
        int root=(1<<n)-1;
        dfs(root);

        double ans=-1;
        for(int i=0;i<v[root].size();i++)
            ans=max(ans,v[root][i].l+v[root][i].r);
            if((int)ans==-1) printf("-1\n");
            else
        printf("%.16f\n",ans);
    }
    return 0;
}
