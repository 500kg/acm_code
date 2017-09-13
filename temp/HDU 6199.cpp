#include<bits/stdc++.h>
using namespace std;
const int maxn = 20050;
int n;
int s[maxn], Sum[maxn];
int dp[2][300][300];
const int mod = 255;
int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d", &n);
		memset(dp, 0, sizeof(dp));
		Sum[0] = 0;
		for (int i = 1; i <= n; i++)
		{
			scanf("%d", &s[i]);
			Sum[i] = Sum[i - 1] + s[i];
		}
		int size = sqrt(n * 2) + 1;
		for (int i = n; i >= 1; i--)
		{
			for (int j = size; j >= 1; j--)
			{
				if (i + j <= n)
				{
					dp[0][i&mod][j] = Sum[(i + j - 1)] - Sum[i - 1] + max(dp[1][(i + j)&mod][j], dp[1][(i + j + 1)&mod][j + 1] + s[i + j]);
					dp[1][i&mod][j] = -Sum[i + j - 1] + Sum[i - 1] + min(dp[0][(i + j)&mod][j], dp[0][(i + j + 1)&mod][j + 1] - s[i + j]);
				}
				else if (i + j == n + 1)
				{
					dp[0][i&mod][j] = Sum[i + j - 1] - Sum[i - 1] + dp[1][(i + j)&mod][j];
					dp[1][i&mod][j] = Sum[i - 1] - Sum[i + j - 1] + dp[0][(i + j)&mod][j];
				}
			}
		}
		printf("%d\n", dp[0][1][1]);
	}


}