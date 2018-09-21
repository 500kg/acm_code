#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[20];
ll dp[20][5];
ll dfs(int pos, int lim, int pre)
{
//	cout << pos << ' ' << pre << endl;
	if (pos == 0&&pre==2)return 1;
	else if (pos == 0)return 0;
	if (!lim&&dp[pos][pre] != -1)return dp[pos][pre];
	int up = lim ? a[pos] : 9;
	ll ans = 0;
	for (int i = 0; i <= up; i++)
	{
		if (pre!=2&&i == 4)
			ans += dfs(pos - 1, lim&&i == up, 1);
		else if (pre == 2 || pre == 1 && i == 9)
			ans += dfs(pos - 1, lim&&i == up, 2);
		else
			ans += dfs(pos - 1, lim&&i == up, 0);
	}
	if (!lim)dp[pos][pre] = ans;
//	cout << pos << ' ' << pre << ' ' << ans << endl;
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
	ll n, m;memset(dp, -1, sizeof(dp));
	int T; cin >> T; while (T--)
	{
		cin >> n;
		cout << solve(n)<< endl;
	//	cout << dp[3][2] << endl;
	}
}