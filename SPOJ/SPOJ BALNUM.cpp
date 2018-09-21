#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll dp[30][60000];
int a[30];int RUA[30];
ll th[30];
ll add(ll sta, int pos)
{
	ll tmp = sta;
	int rua = pos;
	while (rua--)tmp /= 3;
	tmp = tmp % 3;
	if (tmp == 2)
		sta -= th[pos];
	else
		sta += th[pos];
	return sta;
}
int Judge(int state) {   //计算是否满足题意,奇数为偶,偶数为奇
	for (int i = 0; i <= 9; ++i, state /= 3) {
		if ((i & 1) == 1 && state % 3 == 1) {
			return 0;
		}
		if ((i & 1) == 0 && state % 3 == 2) {
			return 0;
		}
	}
	return 1;
}
bool judge(ll sta)
{
	for (int i = 0; i <= 9; i++, sta /= 3)
	{
		int tmp = sta % 3;
		if (tmp == 0)continue;
		if ((i & 1) && tmp == 1)return 0;
		if (!(i & 1) && tmp == 2)return 0;
	}
	return 1;
}
ll dfs(int pos, ll sta, int lim)
{
	if (pos == -1)return judge(sta);
	if (!lim&&dp[pos][sta] != -1)return dp[pos][sta];
	ll ans = 0;
	int up = lim ? a[pos] : 9;
	for (int i = 0; i <= up; i++)
	{
		ll tmp = add(sta, i);
		ans += dfs(pos - 1,sta==0&&i==0?0:tmp , lim&&i == up);
	}
	if (!lim)dp[pos][sta] = ans;
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

	return dfs(pos - 1, 0, 1);
}
int main()
{
	th[0] = 1;
	for (int i = 1; i <= 9; i++)
		th[i] = th[i-1] * 3;
	memset(dp, -1, sizeof(dp));
	int T; cin >> T; while (T--)
	{
		ll a, b;
		cin >> a >> b;
		cout << solve(b) - solve(a - 1) << endl;
	}
}