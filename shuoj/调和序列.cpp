#include<bits/stdc++.h>
using namespace std;
const int maxn = 20005;
int a[maxn];
vector<int> v[maxn];
int n,m;
bool cmp(int a, int b)
{
    return a > b;
}
void ini(int n)
{
    for(int i=0;i<n;i++)
        v[i].clear();
}
void solve()
{
    int k,s;
    scanf("%d%d",&k,&s);
    if(k>=n&&s==1)
    {
        printf("%d\n",a[0]);return;
    }
    if(k>=n||s>v[k].size())
    {
        printf("-1\n");return;
    }
    else printf("%d\n",v[k][s-1]);
}
int main()
{
   // freopen("in.txt", "r", stdin);
    int T;
    cin>>T;while(T--)
    {

        scanf("%d%d",&n,&m);ini(n);
        for(int i=0;i<n;i++)
            scanf("%d",a+i);
        for(int i=1;i<n;i++)
        {
            v[i].push_back(a[0]);
            for(int j=1;j<=(n-1)/i;j++)
                v[i].push_back(a[i*j]);
            sort(v[i].begin(),v[i].end(),cmp);
        }
        while(m--)
        {
            solve();
        }
    }
}
