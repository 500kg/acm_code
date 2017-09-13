#include<bits/stdc++.h>
using namespace std;
int f[30005];
int fin(int i)
{
    while(i!=f[i])
        i=f[i];
    return f[i];
}
void un(int n,int m)
{
    int tn=fin(n);
    int tm=fin(m);
    if(tn!=tm)f[tm]=tn;
}
void ini(int n)
{
    for(int i=0;i<=n;i++)
        f[i]=i;
}
int main()
{
ios::sync_with_stdio(false);
cin.tie(0);
    int n,m,i,k,t,x;
    while(cin>>n>>m)
    {
        if(n==0&&m==0)return 0;
        int cnt=0;
        ini(n);
        while(m--)
        {
            cin>>k;
            cin>>t;
            for(i=1;i<k;i++)
                {cin>>x;un(t,x);}

        }
        x=fin(0);
        for(i=0;i<n;i++)
            if(fin(i)==x)cnt++;
        cout<<cnt<<endl;

    }
}
