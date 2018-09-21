#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int a[100];
int dp[100][100][100];
int dfs(int pos, int num0, int num1, int lim, int fir)
{
//.	cout << pos << ' ' << num0 << ' ' << num1 << endl;
	if (pos == -1)
	{
		if (num0 >= num1)return 1;
		return 0;
	}
	if (!fir && !lim&&dp[pos][num0][num1] != -1)return dp[pos][num0][num1];
	int end = lim ? a[pos] : 1;
	int ans = 0;
	for (int i = 0; i <= end; i++)
	{
		if (fir)
			if (i == 0)
				ans += dfs(pos - 1, 0, 0, i == end && lim, 1);
			else
				ans += dfs(pos - 1, 0, 1, i == end && lim, 0);
		else
			if (i)
				ans += dfs(pos - 1, num0, num1 + 1, lim&&i == end, 0);
			else
				ans += dfs(pos - 1, num0 + 1, num1, lim&&i == end, 0);
	}
	if (!lim && !fir)
		dp[pos][num0][num1] = ans;
	return ans;
}
int solve(int n)
{
	int pos = 0;
	while (n)
	{
		if (n & 1)a[pos++] = 1;
		else a[pos++] = 0;
		n >>= 1;
	}
	return dfs(pos - 1, 0, 0, 1, 1);
}
int main()
{
	int n, m;
	memset(dp, -1, sizeof(dp));
	cin >> n >> m;
	cout << solve(m) - solve(n - 1) << endl;
}