#include<bits/stdc++.h>
using namespace std;
const int maxn = 45;
int dp[maxn][maxn][maxn][maxn], row[maxn][maxn];
int main()
{
	int N, M, Q;
	scanf("%d%d%d", &N, &M, &Q);
	int t;
	for(int i=1;i<=N;i++)
		for (int j = 1; j <= M; j++)
		{
			scanf("%1d", &t);
			row[i][j] = row[i][j - 1];
			if (t)row[i][j] = 0;
			else row[i][j]++;
		}
	for (int a = 1; a <= N; a++)
		for (int b = 1; b <= M; b++)
			for (int c = a; c <= N; c++)
				for (int d = b; d <= M; d++)
				{
					dp[a][b][c][d] = dp[a][b][c - 1][d] + dp[a][b][c][d - 1] - dp[a][b][c - 1][d - 1];
					int tmp = d - b + 1;
					for (int e = c; e >= a&&tmp; e--)
					{
						tmp = min(tmp, row[e][d]);
						dp[a][b][c][d] += tmp;
					}
				}
	int a, b, c, d;
	while (Q--)
	{
		scanf("%d%d%d%d", &a, &b, &c, &d);
		printf("%d\n", dp[a][b][c][d]);
	}
}