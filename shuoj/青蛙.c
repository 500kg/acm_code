#include<stdio.h>
#include<stdlib.h>
long long extgcd(long long a,long long b,long long &x,long long &y)
{
    long long d,t;
    if (b== 0) { x = 1; y = 0; return a;}
    d = extgcd(b, a % b, x, y);
    t = x - a / b * y; x = y; y = t;
    return d;
}
int main()
{
    long long x, y, m, n, L, X, Y, d, r;
    while (scanf("%lld%lld%lld%lld%lld",&x,&y,&m,&n,&L)==5)
    {
        d=extgcd(n-m,L,X,Y);r=L/d;
        if ((x - y) % d||m==n) printf("Impossible\n");
        else printf("%lld\n",((x-y)/d*X%r+r)%r);
    }
    return 0;
}
