#include<bits/stdc++.h>
using namespace std;
long long exgcd(long long a,long long b,long long &x,long long &y)
{
    long long d,t;
    if (b== 0) { x = 1; y = 0; return a;}
    d = exgcd(b, a % b, x, y);
    t = x - a / b * y; x = y; y = t;
    return d;
}
int main()
{
    long long x, y, t, m, n, L, X, Y, d, r;
    while (scanf("%lld%lld%lld%lld%lld",&x,&y,&m,&n,&L)==5)
    {
        d=exgcd(n-m,L,X,Y);r=L/d;
        cout << d << X << Y << r;
        if ((x - y) % d) printf("Impossible\n");
        else {long long s=L/d;
               t=t*((x-y)/d);
               t=(t%s+s)%s;
               cout<<t<<endl;}

    }
    return 0;
}
