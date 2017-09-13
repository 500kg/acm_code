#include<bits/stdc++.h>

using namespace std;
#define mod 1000000007
long long int gcd(long long int x,long long int y)
{
    long long int r,tem;
    if(x>y){tem=x;x=y;y=tem;}
    while(y>0)
    {
        r=x%y;
        x=y;
        y=r;
    }
    return x;
}
long long mypow(long long int x,long long int n,long long int t)
{
    long long int res=1;
    while(n>0)
    {
        if(n&1)res=res*x%t;
        x=x*x%t;;
        n>>=1;
    }
    return res;

}
int main()
{
    long long int m,n,t;
    while(scanf("%lld%lld",&m,&n)==2)
    printf("%lld\n",gcd(m,mypow(n,n,m)));
}
