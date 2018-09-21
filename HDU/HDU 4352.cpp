#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll dp[20][(1 << 11) + 5][11];
ll a[20];
int k;
int check(ll sta)
{
	int ans = 0;
	while (sta)ans += sta & 1, sta /= 2;
	return ans;
}
ll change(ll sta, int pos)
{
	int tmp = sta;
	if (sta&(1 << pos))return sta;
	sta += (1 << pos);

	for (int i = 0; i <= 9&&tmp; i++, tmp /= 2, pos--)
	{
		if (pos < 0 && (tmp & 1))
		{
			sta -= (1 << i);
			return sta;
		}
	}
	return sta;
}
ll dfs(int pos, int sta, int lim, int fir)
{
	int rua = check(sta);
	//	cout << sta << ' ' << rua << endl;
	if (rua > k)return 0;
	if (pos == -1)
	{
		if (rua < k)return 0;
		return 1;
	}
	if (!lim&&dp[pos][sta][k] != -1)return dp[pos][sta][k];
	int up = lim ? a[pos] : 9;
	ll ans = 0;
	for (int i = 0; i <= up; i++)
	{
		ans += dfs(pos - 1, fir&&i == 0 ? 0 : change(sta, i), lim&&i == up, fir&&i == 0);
	}
	if (!lim)dp[pos][sta][k] = ans;
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
	return dfs(pos - 1, 0, 1, 1);
}
int main()
{
	memset(dp, -1, sizeof(dp));
	int kase = 0;
	int T; cin >> T; while (T--)
	{
		ll a, b;
		scanf("%lld%lld", &a, &b); scanf("%d", &k);
		printf("Case #%d: %lld\n",++kase, solve(b) - solve(a - 1));
	}
}