#include<bits/stdc++.h>
using namespace std;
char ch[100005];
int sum[100005];
int getni[10000];
const int mod = 9973;
long long pow_mod(long long x, long long n)
{
	long long base = 1;
	while (n)
	{
		if (n & 1)base = base*x%mod;
		x = x*x%mod;
		n >>= 1;
	}
	return base;
}
void init()
{
	for (int i = 1; i < 9973; i++)
		getni[i] = pow_mod(i, mod - 2);
}
int main()
{
	int n=10000000;
	while (scanf("%d", &n) == 1)
	{
		sum[0] = 1;
		scanf("%s", ch);
		for (int i = 0; ch[i] != '\0'; i++)
			sum[i+1] = sum[i] * (ch[i] - 28) % mod;
		while (n--)
		{
			int l, r;
			scanf("%d%d", &l, &r);
			if (l > r)swap(l, r);
			cout << sum[r] * pow_mod(sum[l - 1], mod - 2) % mod << endl;
		}

	}
}
