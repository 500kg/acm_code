#include<bits/stdc++.h>
using namespace std;
int n, m;
int a[1005][1005], dp[1005][1005];
int main()
{
	int T;
	int kase = 0;
	cin >> T;
	while (T--)
	{
		scanf("%d%d", &n, &m);
		memset(dp, 0, sizeof(dp));
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++)
				scanf("%d", &a[i][j]);
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++)
				dp[i][j] = a[i][j] + max(dp[i - 1][j], dp[i][j - 1]);
		printf("Scenario #%d:\n", ++kase);
		printf("%d\n\n", dp[n][m]);
	}
}