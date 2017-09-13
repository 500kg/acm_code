#include<bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
typedef long long ll;
ll Cm(ll n, ll m);
ll Lucas(ll n, ll m);
ll pow_mod(ll x, ll n);
ll Cm(ll n, ll m)
{
    ll a = 1, b = 1;
    if (m > n) return 0;
    while (m)
    {
        a = (a * n--) % mod;
        b = (b * m--) % mod;
    }
    return (a * pow_mod(b, mod - 2)) % mod;
}
ll lucas(ll n, ll m)
{
    if (m == 0)
        return 1;
    return (Cm(n % mod, m % mod) * lucas(n / mod, m / mod)) % mod;
}

//lucas(a, b)即C(a,b)组合数


ll pow_mod(ll x, ll n)
{
    ll res = 1;
    while (n > 0)
    {
        if (n & 1) res = res * x % mod;
        x = x * x % mod;
        n >>= 1;
    }
    return res;
}
//快速幂 x^n%mod;


int main()
{
    ll a,b,c;
    while(scanf("%lld%lld%lld",&a,&b,&c)==3)
    {
        ll ans=0;
        ans = pow_mod( c , b ) * lucas ( a , b ) % mod;
        cout<<ans<<endl;
    }
}
