#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll Mod = 998244353;
const ll MOD = 998244353;
const ll g = 3;
ll fp(ll a, ll n)
{
	ll base = 1;
	while (n)
	{
		if (n & 1)base = base*a%MOD;
		a = a*a%MOD;
		n >>= 1;
	}
	return base;
}
void change(ll y[], int len)
{
	for (int i = 1, j = len / 2; i<len - 1; i++)
	{
		if (i<j)swap(y[i], y[j]);
		int k = len / 2;
		while (j >= k)
		{
			j -= k;
			k /= 2;
		}
		if (j<k)j += k;
	}
}
void ntt(ll y[], int len, int on)
{
	change(y, len);
	for (int h = 2; h <= len; h <<= 1)
	{
		ll wn = fp(g, (Mod - 1) / h);
		if (on == -1)wn = fp(wn, Mod - 2);
		for (int j = 0; j<len; j += h)
		{
			ll w = 1LL;
			for (int k = j; k<j + h / 2; k++)
			{
				ll u = y[k];
				ll t = w*y[k + h / 2] % Mod;
				y[k] = (u + t) % Mod;
				y[k + h / 2] = (u - t + Mod) % Mod;
				w = w*wn%Mod;
			}
		}
	}
	if (on == -1)
	{
		ll t = fp(len, Mod - 2);
		for (int i = 0; i<len; i++)
			y[i] = y[i] * t%Mod;
	}
}
const int maxn = 1e5 + 50;
ll dp[maxn];
ll x1[maxn*2];
ll x2[maxn*2];
ll inv[maxn];
ll p[maxn];
void cdq(int l, int r)
{
//	cout << l << ' ' << r << endl;
	if (l == r)return;
	int mid = l + r >> 1;
	cdq(l, mid);
	int len = 1;
	while (len <= r - l + 1)len <<= 1;
	for (int i = 0; i < len; i++)
	{
		if (l + i < r)x1[i] = 1LL * (i+1)*(i+1)%MOD;
		else x1[i] = 0;
		if (l + i <= mid)x2[i] = dp[l+i] * inv[l+i] % MOD;
		else x2[i] = 0;
	}
	ntt(x1, len, 1); ntt(x2, len, 1);
	for (int i = 0; i < len; i++)x1[i] = x1[i] * x2[i] % MOD;
	ntt(x1, len, -1);
	for (int i = mid + 1; i <= r; i++)dp[i] = (dp[i] + x1[i - 1 - l] * p[i - 1]) % MOD;
	cdq(mid + 1, r);
}
void init()
{
	p[0] = 1;
	for (int i = 1; i <= 100000; i++)p[i] = p[i - 1] * i%MOD;
	inv[100000] = fp(p[100000], MOD - 2);
	for (int i = 100000 - 1; i>=0; i--)inv[i] = inv[i + 1] * (i + 1) % MOD;
	dp[0] = 1;
//	cout << p[5] * inv[5] % MOD << endl;
	cdq(0, 100000);
}
int main()
{
	init();
	int n;
	while (scanf("%d", &n) == 1)printf("%lld\n", dp[n]);
}
