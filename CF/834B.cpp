#include<bits/stdc++.h>
using namespace std;
const int maxN = 1e6 + 10;
char a[maxN];
int vis[30];
int ans[maxN];
int main()
{
	int n, k;
	cin >> n >> k;
	cin >> a;
	memset(ans, 0, sizeof(ans));
	memset(vis, 0, sizeof(vis));
	for (int i = 0; i < n; i++)
	{
		int t = a[i] - 'A' + 1;
		if (!vis[t])
		{
			vis[t]++;
			ans[i]++;
		}
	}
	memset(vis, 0, sizeof(vis));
	for (int i = n - 1; i >= 0; i--)
	{
		int t = a[i] - 'A' + 1;
		if (!vis[t])
		{
			vis[t]++;
			ans[i + 1]--;
		}
	}
	int res = 0, now = 0;;
	for (int i = 0; i < n; i++)
	{
		now += ans[i];
	//	printf("%d %d\n", now, ans[i]);
		res = max(res, now);
	}
	if (res <= k)puts("NO");
	else puts("YES");
}