#include<bits/stdc++.h>
using namespace std;
int dp[104][104][12];
int ma[104][104][12];
int g0[104][104];
int main()
{
	int n, q, c;
	while (scanf("%d%d%d",&n,&q,&c)==3)
	{
		memset(dp, 0, sizeof(dp));
		for (int i = 0; i < n; i++)
		{
			int x, y, t;
			scanf("%d%d%d", &x, &y, &t);
				dp[x][y][t]++;
		}

		for (int i = 1; i <= 100; i++)
			for (int j = 1; j <= 100; j++)
				for (int k = 0; k <= 10; k++)
					dp[i][j][k] += dp[i - 1][j][k] + dp[i][j - 1][k]-dp[i-1][j-1][k];
	/*	for (int i = 1; i < 20; i++)
		{
			for (int j = 1; j < 20; j++)
				printf("%d",dp[i][j][0] );
			puts("");
		}*/
		for (int i = 0; i < q; i++)
		{
			int t, x1, x2, y1, y2;
			scanf("%d%d%d%d%d", &t, &x1, &y1, &x2, &y2);
			long long ans = 0;
			for (int k = 0; k <= 10; k++)
			{
				long long temp = (dp[x2][y2][k] - dp[x1 - 1][y2][k] - dp[x2][y1 - 1][k] + dp[x1 - 1][y1 - 1][k])*((t + k) % (c + 1));///
				ans += temp;
				//ans += temp;printf("%d %d %d\n",k,temp,ans);
			}
			cout << ans << endl;
		}
	}
}