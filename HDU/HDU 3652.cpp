#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[30];
ll dp[30][30][3000];
ll dfs(int pos, int sta, ll sum, bool lim)
{
	if (pos == -1)
	{
		if (sta == 2 && sum == 0)return 1;
		return 0;
	}
	if (!lim&&dp[pos][sta][sum] != -1)return dp[pos][sta][sum];
	int up = lim ? a[pos] : 9;
	ll ans = 0;
	for (int i = 0; i <= up; i++)
	{
		if ((sta == 1 && i == 3) || sta == 2)
			ans += dfs(pos - 1, 2, (sum * 10 + i) % 13, lim&&i == up);
		else if (i == 1)
			ans += dfs(pos - 1, 1, (sum * 10 + i) % 13, lim&&i == up);
		else
			ans += dfs(pos - 1, 0, (sum * 10 + i) % 13, lim&&i == up);
	}
//	cout << pos << ' ' << sta << ' ' << sum << ' ' << ans << endl;
	if (!lim)dp[pos][sta][sum] = ans;
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
	return dfs(pos - 1, 0, 0, 1);

}
int main()
{
	memset(dp, -1, sizeof(dp)); ll n;

	int T; while (cin >> n)
	{

		cout << solve(n) << endl;
	}
}