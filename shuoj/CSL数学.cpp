#include<bits/stdc++.h>
using namespace std;
const int MOD=1000000007;
long long int a[300006];
long long t[300006];

void f()
{
    a[0]=1;a[1]=2;
    for(int i=2;i<=300006;i++)
        a[i]=2*a[i-1]%MOD;
}
int main()
{
    f();
    int n,i;
    while(scanf("%d",&n)==1)
    {
        for(i=0;i<n;i++)
            scanf("%lld",&t[i]);
        sort(t,t+n);
        long long ans=0;
        for(i=0;i<n;i++)
            ans=(ans+t[i]*(a[i]-a[n-i-1]))%MOD;
        printf("%lld\n",(ans + MOD) % MOD);
    }
}
