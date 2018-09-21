#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;
ll a[30];
struct node
{
	ll cnt;
	ll sum;
	ll qsum;
	node() {}node(ll _cnt, ll _sum, ll _qsum)
	{
		cnt = _cnt;
		sum = _sum;
		qsum = _qsum;
	}
}dp[30][10][10];
ll p[30];
node dfs(int pos, ll sum1, ll sum2, bool lim)
{
	if (pos == -1)
	{
		if (sum1 && sum2)return node(1, 0, 0);
		return node(0, 0, 0);
	}
	if (!lim&&dp[pos][sum1][sum2].cnt != -1)return dp[pos][sum1][sum2];
	int up = lim ? a[pos] : 9;
	node tmp;
	node ans = node(0, 0, 0);
	for (int i = 0; i <= up; i++)
	{
		if (i == 7)continue;
		tmp = dfs(pos - 1, (sum1 + i) % 7, (sum2 * 10 + i) % 7, lim&i == up);
		ans.cnt += tmp.cnt;
		ans.cnt %= MOD;
		ans.sum += (tmp.sum + i * p[pos] % MOD*tmp.cnt%MOD) % MOD;
		ans.sum %= MOD;
		ans.qsum += (tmp.qsum + 2 * p[pos] * i%MOD*tmp.sum%MOD) % MOD;
		ans.qsum %= MOD;
		ans.qsum += (tmp.cnt*p[pos] % MOD*p[pos] % MOD*i*i%MOD);
		ans.qsum %= MOD;


	}
	if (!lim)dp[pos][sum1][sum2] = ans;
	return ans;
}
ll solve(ll n)
{
	int pos = 0;
	while (n)
	{
		a[pos++] = n % 10;
		n /= 10;
	}
	return dfs(pos - 1, 0, 0, 1).qsum;
}
int main()
{
	p[0] = 1;
	for (int i = 0; i <= 19; i++)
		for (int j = 0; j < 9; j++)
			for (int k = 0; k < 9; k++)
				dp[i][j][k].cnt = -1;
	for (int i = 1; i <= 19; i++)p[i] = (p[i - 1] * 10) % MOD;
	int T; cin >> T; while (T--)
	{
		ll n, m;
		cin >> n >> m;
		cout << (solve(m) - solve(n - 1) + MOD) % MOD << endl;
	}
}