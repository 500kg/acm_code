#include<bits/stdc++.h>
using namespace std;
#define  V 15000
int f[V];
int w[V];
int v[V];

int main()
{
freopen("in.txt","r",stdin);
    int t,m;
    while(scanf("%d%d",&t,&m)==2)
    {
        memset(f,0,sizeof(f));
        for (int i=1;i<=t; i++)
    {
        cin>>w[i]>>v[i];
    }
    for (int i=1; i<=t; i++)
        for (int j=m; j>=1; j--)
        {
            if (w[i]<=j)
            {
                f[j]=max(f[j],f[j-w[i]]+v[i]);
            }
        }

    cout<<f[m]<<endl;
    }
}
