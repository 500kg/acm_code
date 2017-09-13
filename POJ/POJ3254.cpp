#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
const int mod = 100000000;
int n, m;
int ma[15][15];
int dp[15][(1 << 12)+ 10];
int stddd[(1 << 12) + 10];
vector<int> temp[15];
int ok(int x)
{
	int s = 0;
	for (int i = 1; i <= m; i++)
		if (!ma[x][i])
			s += (1 << m - i);
	return s;
}
void init()
{
	int t = 1 << 12;
	for (int i = 0; i <= t; i++)
		stddd[i] = (i&(i >> 1));
}
int main()
{
	init();
	while (scanf("%d%d", &n, &m) == 2)
	{
		memset(dp, 0, sizeof(dp));
		memset(temp, 0, sizeof(temp));
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++)
				scanf("%d", &ma[i][j]);
		
		temp[0].push_back(0);
		int k = 1 << m;
		for (int i = 0; i < k; i++)
			dp[0][i] = 1;
		for (int i = 1; i <= n; i++)
		{
			int cur = ok(i);
			for (int j = 0; j < k; j++)
			{
				if (stddd[j])continue;
				//if (j&(j>>1))continue;
				if (j&cur)continue;
				temp[i].push_back(j);
			}
			for (int j = 0; j < temp[i].size(); j++)
			{
				int u = temp[i][j];
				for (int k = 0; k < temp[i - 1].size(); k++)
				{
					int v = temp[i - 1][k];
					if (u & v)continue;
					dp[i][u] = (dp[i][u] + dp[i - 1][v]) % mod;
				}
			}
		}
		int ans = 0;
		for (int i = 0; i < k; i++)
		{
			ans = (ans + dp[n][i]) % mod;
		//	cout << dp[n][i] << endl;
		}
		printf("%d\n", ans);
	}
}