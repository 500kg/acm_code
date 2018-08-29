#include<bits/stdc++.h>
using namespace std;
const int N = 55;
int w[N][N];
int dist[N][N];
int dp[N][N][N * 2];
int dp2[N][N][N * 2];
int dp3[N][N][N * 2];
int min1(int a, int b)
{
	if (a == -1)return b;
	if (b == -1)return a;
	return min(a, b);
}
int main()
{
	int T; cin >> T; while (T--)
	{
		int n, m;
		scanf("%d%d", &n, &m);
		memset(w, -1, sizeof(w));
		memset(dp, -1, sizeof(dp));
		memset(dp3, -1, sizeof(dp3));
		memset(dp2, -1, sizeof(dp2));
		memset(dist, -1, sizeof(dist));
		for (int i = 0, u, v, val; i < m; i++)
		{
			scanf("%d%d%d", &u, &v, &val);
			w[u][v] = min1(w[u][v], val);
		}
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++)
				dist[i][j] = w[i][j];
			dist[i][i] = 0;
		}
		for (int i = 1; i <= n; i++)dp2[i][i][0] = dp[i][i][0] = 0;
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				for (int k = 1; k <= n; k++)
					if (dist[j][i] != -1 && dist[i][k] != -1)
					dist[j][k] = min1(dist[j][k], dist[j][i] + dist[i][k]);
		for (int k = 1; k <= 100; k++)
			for (int i = 1; i <= n; i++)
				for (int j = 1; j <= n; j++)
					for (int l = 1; l <= n; l++)
						if (dp[i][l][k - 1] != -1 && w[l][j] != -1)
					dp[i][j][k] = min1(dp[i][j][k], dp[i][l][k - 1] + w[l][j]);

		
		for (int k = 1; k <= 100; k++)
			for (int i = 1; i <= n; i++)
				for (int j = 1; j <= n; j++)
					for (int l = 1; l <= n; l++)
						if(dp2[i][l][k-1]!=-1&&dp[l][j][100]!=-1)
						dp2[i][j][k] = min1(dp2[i][j][k], dp2[i][l][k - 1] + dp[l][j][100]);
		for (int k = 0; k <= 100; k++)
			for (int i = 1; i <= n; i++)
				for (int j = 1; j <= n; j++)
					for (int l = 1; l <= n; l++)
						if (dp[i][l][k] != -1 && dist[l][j] != -1)
						dp3[i][j][k] = min1(dp3[i][j][k], dp[i][l][k] + dist[l][j]);
		int q;
		scanf("%d", &q);
		int u, v, k;
		while (q--)
		{
			scanf("%d%d%d", &u, &v, &k);
			int A = k / 100, B = k % 100;
			int ans = -1;
			for (int i = 1; i <= n; i++)
					if (dp2[u][i][A] != -1 && dp3[i][v][B] != -1)
						ans = min1(ans, dp2[u][i][A] + dp3[i][v][B]);
			//	cout << dp2[u][i][A] << ' ' << dp3[i][v][B] << endl;
			printf("%d\n", ans);
	
			
		}
	}
}