#include<bits/stdc++.h>
using namespace std;
int dig[100];
int dp[20][15][2][10];  //位数，模13加法，是否包含13，末尾数
long long dfs(int pos, int sum, bool i13, int e, int flag)//flag为对末尾数的限制
{
	if (pos == -1)
		return i13&&sum == 0;   //若包含13且是13的倍数就算一个
	if (!flag&&dp[pos][sum][i13][e] != -1)
		return dp[pos][sum][i13][e];
	int end = flag ? dig[pos] : 9;
	int ans = 0;
	for (int i = 0; i <= end; i++)
		ans += dfs(pos - 1, (sum * 10 + i) % 13, i13 || i == 3 && e == 1, i, flag && (i == end));
	if (!flag)dp[pos][sum][i13][e] = ans;
	return ans;
}
long long solve(long long n)
{
	int cnt = 0;
	while (n)
	{
		dig[cnt++] = n % 10;
		n /= 10;
	}
	return dfs(cnt - 1, 0, 0, 0, 1);
}
int main()
{
	long long n;
	memset(dp, -1, sizeof(dp));
	while (scanf("%lld", &n) == 1)
	{
		printf("%lld\n", solve(n));
	}
}