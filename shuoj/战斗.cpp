#include<bits/stdc++.h>
#include<stdlib.h>
using namespace std;
struct g
{
    int x;
    int g;

}a[11],b[11];
bool cmp(struct g a,struct g b)
{
    if(a.g<b.g)return 1;
    else if(a.g==b.g)if(a.x>b.x)return 0;
    return 1;
}
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int n;
        cin>>n;
        for(int i=0;i<n;i++)
            cin>>a[i].x>>a[i].g;
        for(int i=0;i<n;i++)
            cin>>b[i].x>>b[i].g;
        sort(b,b+n,cmp);
       /* for(int i=0;i<n;i++)
            cout<<b[i].x<<b[i].g<<endl;*/
        int i=0,j=0;
        while(i<n&&j<n)
        {
            a[i].x-=b[j].g;
            b[j].x-=a[i].g;
            if(a[i].x<=0)i++;
            if(b[j].x<=0)j++;
        }
        if(j<n)puts("YES");
        else puts("NO");

    }
}
/*#include<bits/stdc++.h>
#include<stdlib.h>
using namespace std;
int nx[15],ng[15],wx[15],wg[15];
int x[15],g[15],a[15],b[15];
int T,n,flag;
int order[10]= {0,1,2,3,4,5,6,7,8,9};
void solve()
{
    for(int i=0;i<n;i++)
    {
        nx[i]=x[i];
        wx[i]=a[i];
    }
    int i=0,j=0;
    while(i<n&&j<n)
    {
        int time=min(nx[i]/wg[order[j]],wx[order[j]]/ng[i]);
        nx[i]-=(wg[order[j]]*time);
        wx[order[j]]-=(ng[i]*time);
        while(wx[order[j]]>0&&nx[i]>0)
        {
            nx[i]-=wg[order[j]];
            wx[order[j]]-=ng[i];
        }
        if(nx[i]<=0)
            i++;
        if(wx[order[j]]<=0)
            j++;
    }
    if(j<n)flag=1;

}
int main()
{ ios_base::sync_with_stdio(0);cin.tie(0);
  //  freopen("in.txt","r",stdin);
  //
    cin>>T;
    while(T--)
    {
        cin>>n;
        for(int i=0;i<n;i++)
            cin>>x[i]>>ng[i];
        for(int i=0;i<n;i++)
            cin>>a[i]>>wg[i];
        int flag=0;
    do{
            solve();
            if(flag)break;
    }while(next_permutation(order,order+n));
    if(flag)puts("YES");
    else puts("NO");
    }
}
*/
