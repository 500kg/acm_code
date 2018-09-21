#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[20];
ll dp[20][2];
ll dfs(int pos, int lim, int pre)
{
	if (pos == 0)return 1;
	if (!lim&&dp[pos][pre] != -1)return dp[pos][pre];
	int up = lim ? a[pos] : 9;
	ll ans = 0;
	for (int i = 0; i <= up; i++)
	{
		if (i == 4)continue;
		if (pre&&i == 2)continue;
		ans += dfs(pos - 1, lim&&i == up, i == 6);
	}
	if (!lim)dp[pos][pre] = ans;
	return ans;
}
ll solve(ll n)
{
	int pos = 0;
	while (n)
	{
		a[++pos] = n % 10;
		n /= 10;
	}
	return dfs(pos, 1, 0);
}
int main()
{
	ll n, m;
			memset(dp, -1, sizeof(dp));
	while (cin >> n >> m && (n + m))
	{

		cout << solve(m) - solve(n-1) << endl;
	}
}