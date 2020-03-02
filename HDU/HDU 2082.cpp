#include<bits/stdc++.h>
using namespace std;
int a[30];
int c1[100], c2[100];
void ini()
{
	for (int i = 0; i<55; i++)
	{#include<cstring>
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
		c1[i] = 0;
		c2[i] = 0;
	}
}
int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		ini();
		for (int i = 1; i <= 26; i++)
			scanf("%d", &a[i]);
		c1[0] = 1;
		for (int i = 1; i <= 26; i++)
		{
			for (int j = 0; j <= 50; j++)
				for (int k = 0; k <= a[i] && k*i + j <= 50; k++)
					c2[k*i + j] += c1[j];
			for (int j = 0; j <= 50; j++)
			{
				c1[j] = c2[j];
				c2[j] = 0;
			}
		}
		long long int ans = 0;
		for (int i = 1; i <= 50; i++)///指数是0的不算单词
			ans += c1[i];
		cout << ans << endl;
	}
}
