#include<stdio.h>
#define lli long long

lli egcd(lli a, lli b, lli *x, lli *y) {
    lli d, x1, y1;
    if (b == 0) {
        d = a;
        *x = 1;
        *y = 0;
    }
    else {
        d = egcd(b, a % b, &x1, &y1);
        *x = y1;
        *y = x1 - a / b * y1;
    }
    return d;
}

main() {
    lli a, b, x, y, m, n, L, d;
    while(scanf("%lld%lld%lld%lld%lld", &x, &y, &m, &n, &L) != -1) {
        a = m < n ? n - m : m - n;
        b = m < n ? x - y : y - x;
        b = (L + b) % L;
        d = egcd(a, L, &x, &y);
        if ( b % d)
            printf("Impossible\n");
        else {
            for(x *= b / d, L /= d; x < 0; x += L);
            printf("%lld\n", x % L);
        }
    }
}
