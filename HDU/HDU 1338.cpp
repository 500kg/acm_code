#include<bits/stdc++.h>
using namespace std;
int m, n;
int a[100], vis[1005];
int cas = 1;
void solve()
{
	sort(a, a + n);
	int now = 1, j = 1;
	int ans = 0;
	/*	for (int i = 60; i <= 66; i++)
	printf("%d ", vis[i]);
	puts("");*/

	for (int i = m*n; j <= n; i--, j++)
	{
		if (a[n - j] == i)ans++;
		else if (vis[i]) 
		{
			j--; continue;
		}
	}
	/*for (int i = 60; i <= 66; i++)
	printf("%d ", vis[i]);
	puts("");*/
	printf("Case %d: %d\n", cas++, ans);
}
int main()
{
	while (scanf("%d%d", &m, &n) == 2)
	{
		memset(vis, 0, sizeof(vis));
		if (m == 0 && n == 0)break;
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
			vis[a[i]] = 1;
		}
		solve();
	}
	return 0;
}