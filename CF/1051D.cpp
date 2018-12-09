#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 998244353;
ll dp[2000][2005][2][2];
int main()
{
	std::ios::sync_with_stdio(false);
	int n, k;
	cin >> n >> k;
	dp[1][1][0][0] = 1;
	dp[1][1][1][1] = 1;
	dp[1][2][0][1] = dp[1][2][1][0] = 1;
	for (int i = 2; i <= n; i++)
	{
		for (int j = 1; j <= k; j++)
		{
			dp[i][j][0][0] += dp[i - 1][j][0][0];
			dp[i][j][0][0] += dp[i - 1][j][0][1];
			dp[i][j][0][0] += dp[i - 1][j][1][0];
			dp[i][j][0][0] += dp[i - 1][j - 1][1][1];

			dp[i][j][0][1] += dp[i - 1][j][0][1];
			dp[i][j][0][1] += dp[i - 1][j-1][1][1];
			if (j >= 2)dp[i][j][0][1] += dp[i - 1][j-2][1][0];
			dp[i][j][0][1] += dp[i - 1][j-1][0][0];

			if(j>=2)dp[i][j][1][0] += dp[i - 1][j-2][0][1];
			dp[i][j][1][0] += dp[i - 1][j-1][1][1];
			dp[i][j][1][0] += dp[i - 1][j][1][0];
			dp[i][j][1][0] += dp[i - 1][j-1][0][0];

			dp[i][j][1][1] += dp[i - 1][j][0][1];
			dp[i][j][1][1] += dp[i - 1][j][1][1];
			dp[i][j][1][1] += dp[i - 1][j][1][0];
			dp[i][j][1][1] += dp[i - 1][j - 1][0][0];

			for (int G = 0; G < 2; G++)
				for (int p = 0; p < 2; p++)
					dp[i][j][G][p] %= MOD;
		//	if(dp[i][j][0][0]+dp[i][j][0][1])
		//	::cout << i << ' ' << j << ' ' << dp[i][j][0][0] <<' '<<dp[i][j][0][1]<<' '<<dp[i][j][1][0]<<' '<<dp[i][j][1][1]<< endl;
		}
	}
	ll ans = 0;
	for (int G = 0; G < 2; G++)
		for (int p = 0; p < 2; p++)
			ans += dp[n][k][G][p];
	ans %= MOD;
	std::cout << ans << endl;
}