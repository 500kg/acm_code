#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[10];
ll dp[10][200000];
ll RUA;
ll dfs(int pos, ll sum, bool lim)
{
	if (sum < 0)return 0;
	if (pos == -1)return 1;
//	cout << pos << ' ' << sum << ' ' << lim << ' ' << fir << endl;
	if (!lim&&dp[pos][sum] != -1)return dp[pos][sum];
	int up = lim ? a[pos] : 9;
	ll ans = 0;
	for (int i = 0; i <= up; i++)
	{
		ans += dfs(pos - 1, sum - (i << pos) , lim&&i == up);
	}
	if (!lim)dp[pos][sum] = ans;
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
	return dfs(pos - 1, RUA, 1);
}
ll gao(ll m)
{
	int pos = 1;
	ll ans = 0;
	while (m)
	{
		ans += pos * (m % 10);	pos *= 2;
		m /= 10;
	}
	return ans;
}
int main()
{
	 ll n;
	ll m;
	int kase = 0;memset(dp, -1, sizeof(dp));
	int T; cin >> T; while (T--)
	{
		
		scanf("%lld%lld", &m, &n);
		RUA = gao(m); //cout << RUA << endl;
		printf("Case #%d: %lld\n", ++kase, solve(n));
	//	cout << "Case #" << ++kase << ": " << solve(n) << endl;
	}
}