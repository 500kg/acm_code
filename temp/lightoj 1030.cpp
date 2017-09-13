#include<cstdio>
#include<cmath>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
double dp[1000];
int main()
{
	int T, kase = 0;
	cin >> T;
	while (T--)
	{
		memset(dp, 0, sizeof(dp));
		int n;
		cin >> n;
		for (int i = 1; i <= n; i++)
			cin >> dp[i];
		for (int i = n - 1; i >= 1; i--)
		{
			double k = min(6, n - i);
			double temp = 0;
			for (int j = i + 1; j <= i + k; j++)
				temp += dp[j];
			dp[i] += temp / k;
		}
		printf("Case %d: %.6lf\n", ++kase, dp[1]);
	}
}