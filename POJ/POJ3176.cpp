#include<algorithm>
#include<iostream>
using namespace std;
int a[355][355], dp[355][355];

int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= i; j++)
			cin >> a[i][j];
	memset(dp, 0, sizeof(dp));
	dp[1][1] = a[1][1];
	for (int i = 2; i <= n; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1]) + a[i][j];
			//cout << dp[i][j]<<" ";
		}
	//	puts("");
	}
	int mox = 0;
	for (int i = 1; i <= n; i++)
		mox = max(mox, dp[n][i]);
	cout << mox << endl;
}