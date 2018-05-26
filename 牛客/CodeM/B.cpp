#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,m,k;
    cin>>n>>m>>k;
    double now=0;
    int pos=0;
    for(int i=1;i<=k;i++)
    {
        int x,y;cin>>x>>y;
        double tmp=1.0*x*m/n+1.0*y*(m-n)/n;
        if(tmp>now)
        {
            pos=i;
            now=tmp;
        }
    }
    for(int i=1;i<=k;i++)
    {
        if(i==pos)
        printf("%d%c",n,i==k?'\n':' ');
        else
        printf("0%c",i==k?'\n':' ');
    }
    system("pause");
}