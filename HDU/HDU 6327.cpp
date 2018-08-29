#include<bits/stdc++.h>
using namespace std;
struct node
{
	int x, y, z;
	node() {}node(int _x, int _y, int _z)
	{
		x = _x; y = _y, z = _z;
	}
}st[2000]; const int MOD = 1e9 + 7;
int tot;
int id[105][105][105];
typedef long long ll;
ll inv[110];
void init()
{
	tot = 0;
	for (int i = 1; i <= 100; i++)
		for (int j = 1; j <= i; j++)
			if (i%j == 0)
				for (int k = 1; k <= j; k++)
					if (j%k == 0)
					{
						st[++tot] = node(i, j, k);
						id[i][j][k] = tot;

					}
	inv[1] = 1;
	for (int i = 2; i<110; i++)
		inv[i] = 1LL * (MOD - MOD / i)*inv[MOD%i] % MOD;
}

ll a[105], v[105];
ll dp[105][2000];
int G[200][200];
int gcd(int a, int b)
{
	if (G[a][b])return G[a][b];
	if (!b)return a;
	return G[b][a%b]=gcd(b, a%b);
}
ll pw2(ll a, ll n = MOD - 2)
{
	ll ret = 1;
	while (n)
	{
		if (n & 1)ret = ret*a%MOD;
		a = a*a%MOD;
		n >>= 1;
	}
	return ret;
}
int main()
{
	init();

	int T; cin >> T; while (T--)
	{
		int n, m;
		scanf("%d%d", &n, &m);
		for (int i = 1; i <= n; i++)scanf("%lld", &a[i]);
		for (int i = 1; i <= m; i++)scanf("%lld", &v[i]);
		for (int i = 0; i <= n; i++)for (int j = 0; j <= tot; j++)dp[i][j] = 0;
		for (int i = 1; i <= m; i++)
			if (!a[1] || a[1] == i)
				for (int j = 1; j <= m; j++)
					if (!a[2] || a[2] == j)
						for (int k = 1; k <= m; k++)
							if (!a[3] || a[3] == k)
							{
								int y = gcd(k, j), z = gcd(y, i);
								int index = id[k][y][z];
								dp[3][index]++;
							}
		for (int i = 3; i < n; i++)
		{
			for (int j = 1; j <= tot; j++)
			{
				if (!dp[i][j])continue;
				int x = st[j].x, y = st[j].y, z = st[j].z;
				for (int k = 1; k <= m; k++)
				{
					if (a[i + 1] && a[i + 1] != k)continue;
					int  yy = gcd(k, x), zz = gcd(k, y);
					int ide = id[k][yy][zz];
					dp[i + 1][ide] += (1LL * dp[i][j] * v[gcd(k, z)]) % MOD;
						while (dp[i + 1][ide] >= MOD)dp[i + 1][ide] -= MOD;
					//	cout <<i+1<<' '<<' '<<x<<' '<<y<<' '<<z<<' '<< dp[i + 1][ide] << endl;
				}
			}
		}
		ll ans = 0;
		for (int i = 1; i <= tot; i++)ans += dp[n][i]; ans %= MOD;
		ll inv = pw2(m);
		for (int i = 1; i <= n; i++)if (!a[i])ans = ans*inv%MOD;
		printf("%lld\n", ans);
	}
}