#include<bits/stdc++.h>
using namespace std;
const int MOD=1000000007;
long long int a[100005],p[100005];

void y()
{
    p[1]=1,a[1]=1,a[0]=1;
    for(int i=2;i<=100000;i++)
       {
           p[i]=p[i-1]*i%MOD;
           a[i]=(a[i-1]*p[i])%MOD;
       }
}
int main()
{
    y();    //0.047s
    int n,m;
    while(scanf("%d%d",&n,&m)==2)
    {
        n--;
        long long int ans=((a[m]%(a[n]*MOD))/a[n])%MOD;

        printf("%lld\n",ans);
        printf("%lld %lld\n",a[n],a[m]);
    }
   /* for(int i=1;i<30;i++)
        printf("%lld %lld\n",a[i],p[i]);*/
}
