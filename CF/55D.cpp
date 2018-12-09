#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
ll dp[25][60][2600];
int a[30];
int idex[3000];
int gcd(int a, int b)
{
	if (!b)return a;
	return gcd(b, a%b);
}
int lcm(int a, int b)
{
	return a / gcd(a, b)*b;
}
ll dfs(int pos, int lc, int sum, bool lim)
{
	if (pos == -1)
	{
		return sum%lc == 0;
	}
	if (idex[lc] > 50)cout << lc << endl;
	if (!lim&&dp[pos][idex[lc]][sum] != -1)return dp[pos][idex[lc]][sum];
	ll ans = 0;
	int up = lim ? a[pos] : 9;
	for (int i = 0; i <= up; i++)
		ans += dfs(pos - 1, i?lcm(lc, i):lc, (sum * 10 + i) % 2520, lim&&i == up);
	if (!lim)dp[pos][idex[lc]][sum] = ans;
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
	return dfs(pos - 1, 1, 0, 1);
}
int main()
{
	int tot = 1;
	for (int i = 1; i <= 2520; i++)
		if (2520 % i == 0)
			idex[i] = tot++;
//	cout << tot << endl;
	memset(dp, -1, sizeof(dp));
	int T; cin >> T; while (T--)
	{
		ll a, b;
		cin >> a >> b;
		cout << solve(b) - solve(a - 1) << endl;
	}
}