#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[30];
ll dp[30][30][3000];
ll dfs(int pos, int rua, ll sum, bool lim)
{
	if (sum < 0)return 0;
	if (pos == -1)return sum == 0;
	if (!lim&&dp[pos][rua][sum] != -1)return dp[pos][rua][sum];
	int up = lim ? a[pos] : 9;
	ll ans = 0;
	for (int i = 0; i <= up; i++)
	{
		ans += dfs(pos - 1, rua, sum + (pos - rua)*i, lim&&i == up);
	}
	if (!lim)dp[pos][rua][sum] = ans;
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
	ll ans = 0;
	for (int i = 0; i < pos; i++)
		ans+=dfs(pos - 1, i, 0, 1);
	return ans - (pos - 1);//0加了pos次

}
int main()
{
	memset(dp, -1, sizeof(dp));
	int T; cin >> T; while (T--)
	{
		ll n, m;
		cin >> n >> m;
		cout << solve(m) - solve(n - 1) << endl;
	}
}