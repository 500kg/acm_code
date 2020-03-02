#include<bits/stdc++.h>
using namespace std;
int dp[10][10]; //[i][j]长度为i首位为j的有几个符合条件

void init()
{
	memset(dp, 0, sizeof(dp));
	for (int i = 0; i < 10; i++)
		dp[1][i] = 1;
	dp[1][4] = 0;
	for (int i = 2; i <= 7; i++)
		for (int j = 0; j < 10; j++)
			for (int k = 0; k < 10; k++)
				if (j != 4 && !(j == 6 && k == 2))
					dp[i][j] += dp[i - 1][k];
}
int dig[100];
int solve(int x)
{
	int cnt = 0;
	int ans = 0;
	while (x)
	{
		dig[++cnt] = x % 10;
		x /= 10;
	}
	dig[cnt + 1] = 0;
	for (int i = cnt; i > 0; i--)
	{
		for (int j = 0; j < dig[i]; j++)
		{
			if (j != 4 &&! (j == 2 && dig[i + 1] == 6))
				ans += dp[i][j];
		}
		if (dig[i] == 4 || dig[i + 1] == 6 && dig[i] == 2)
			break;
	}
	return ans;
}
int main()
{
	init();
	int l, r;
	while (scanf("%d%d", &l, &r) == 2)
	{
		if (l + r == 0)return 0;
		cout << solve(r + 1) - solve(l) << endl;
	}
}