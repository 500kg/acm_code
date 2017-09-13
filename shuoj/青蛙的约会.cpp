#include<iostream>
#include<bits/stdc++.h>

typedef long long dnt;
using namespace std;
dnt x, y;
dnt a, b, m, n, L;
dnt Exgcd( dnt a, dnt b, dnt &x, dnt &y ) {
    if ( b == 0 ) {
        x = 1;
        y = 0;
        return a;
    }
    dnt d =  Exgcd(b, a%b, x, y), temp = x;
    x = y;
    y = temp-a/b*y;
    return d;
}

dnt solv( dnt a, dnt b, dnt c ) {
    dnt d = Exgcd(a, b, x, y);
    if ( c % d ) return -1;
    x = x * c / d;
    y = y * c / d;
    x = (x % b + b) % b;
    return x;
}
int main() {
    while (scanf("%lld%lld%lld%lld%lld",&a,&b,&m,&n,&L)==5)
    {
    if (solv(n-m,L,a-b)!=-1)
    printf("%lld\n",solv(n-m,L,a-b));
    else puts("Impossible");}
    return 0;
}
