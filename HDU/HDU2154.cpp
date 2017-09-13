#include<cstring>
#include<stdio.h>
#include<algorithm>
#include<cmath>
#include<iostream>
using namespace std;
const int maxn = 50000 + 50;
int isprime[maxn];
int prime[maxn], len;
void sieve()
{
	for (int i = 0; i <= 50000; i++)
		isprime[i] = 1;
	isprime[0] = isprime[1] = 0;
	for (int i = 2; i <= 50000; i++)
	{
		if (isprime[i])
		{
			prime[len++] = i;
			for (int j = 2 * i; j <= 50000; j += i)
				isprime[j] = 0;
		}
	}
}

int euler(int n)
{
	int res = n;
	for (int i = 0; i<len&&prime[i] * prime[i] <= n; i++)
	{
		if (n%prime[i] == 0)
		{
			res = res / prime[i] * (prime[i] - 1);
			while (n%prime[i] == 0)
				n /= prime[i];
		}
	}
	if (n>1)
		res = res / n*(n - 1);
	return res;
}

int n, p;
long long pow(int a, int n, int mod)
{
	int base = 1;
	a = a%mod;
	while (n)
	{
		if (n & 1)
			base = base*a%mod;
		a = a*a%mod;
		n >>= 1;
	}
	return base;
}
void solve()
{
	long long ans = 0;
	for (int i = 1; i*i <= n; i++)
	{
		if (n%i)
			continue;
		else
			ans = (ans + (euler(i) % p*pow(n, n / i - 1, p)) % p) % p;
		if (i*i == n)break;
			ans = (ans + euler(n / i) % p*pow(n, i - 1, p)) % p;
	}
	cout << ans << endl;
}
int main()
{
	sieve();
	int T; cin >> T; while (T--)
	{
		scanf("%d%d", &n, &p);
		solve();
	}
}
