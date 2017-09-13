#include<bits/stdc++.h>
using  namespace std;
const int INF = 0x3f3f3f3f;
const int maxn = 20202;
int  n;
int sum[maxn], ans;
int dp[maxn][210];
int dfs(int su, int pos, int step, int peo)//peo为1Alice
{

	if (peo&&dp[pos][step] != -1)return dp[pos][step];
	if (pos + step > n)return peo == 0? su :dp[pos][step] = su;
	if (peo)return dp[pos][step] = min(dfs(su + sum[pos + step] - sum[pos], pos + step, step, !peo), dfs(su + sum[pos + step + 1] - sum[pos + 1], pos + step + 1, step + 1, !peo));
	else return max(dfs(su - sum[pos + step] + sum[pos], pos + step, step, !peo), dfs(su - sum[pos + step + 1] + sum[pos + 1], pos + step + 1, step + 1, !peo));
}
int dfs2(int su, int pos, int step, int peo)//peo为1Alice
{
	if (peo&&dp[pos][step] != -1)return dp[pos][step];
	if (pos + step > n)return peo == 0 ? su : dp[pos][step]= su;
	if (peo)return dp[pos][step] = max(dfs2(su + sum[pos + step] - sum[pos], pos + step, step, !peo), dfs2(su + sum[pos + step + 1] - sum[pos + 1], pos + step + 1, step + 1, !peo));
	else return min(dfs2(su - sum[pos + step] + sum[pos], pos + step, step, !peo), dfs2(su - sum[pos + step + 1] + sum[pos + 1], pos + step + 1, step + 1, !peo));
}
int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		memset(sum, 0, sizeof(sum));
		scanf("%d", &n);
		int t;
		for (int i = 1; i <= n; i++)
		{
			scanf("%d", &t);
			sum[i] = sum[i - 1] + t;
		}
		memset(dp, -1, sizeof(dp));
		ans = max(abs(dfs(sum[1], 1, 1, 0)), abs(dfs(sum[2], 2, 2, 0)));
		memset(dp, -1, sizeof(dp));
		ans = max(ans, max(abs(dfs2(sum[1], 1, 1, 0)), abs(dfs2(sum[2], 2, 2, 0))));
		printf("%d\n", ans);
	}
}