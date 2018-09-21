#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e4 + 50;
double dp[maxn];

int main()
{
	int T, kase = 0; cin >> T; while (T--)
	{
		double ans = 0, now = 1;
		int cnt = 0;
		int n; scanf("%d", &n);
		while (ans < 0.5)
		{
			now = now*(n - cnt) / n;
			ans = 1 - now;
			cnt++;
		}
		printf("Case %d: %d\n", ++kase, cnt - 1);

	}
}