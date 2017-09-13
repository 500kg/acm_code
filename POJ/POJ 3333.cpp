#include<bits/stdc++.h>
using namespace std;
struct node
{
	int t, td, tc;
}a[105];
int ans;
int vis[105];
int n;
void dfs(int cur, int sum)
{
	if (cur == n)
	{
		ans = max(ans, sum);
		return;
	}
	if (vis[cur])
		dfs(cur + 1, sum + a[cur].t);
	else
	{
		if (a[cur].tc > cur)
		{
			vis[cur] = 1;
			dfs(cur + 1, sum + a[cur].t);
			vis[cur] = 0;
		}
			vis[cur] = 1;
			dfs(a[cur].tc, sum + a[cur].td);
			vis[cur] = 0;
	}
}
int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
		{
			scanf("%d%d%d", &a[i].t, &a[i].td, &a[i].tc);
			a[i].tc--;
		}
		ans = 0;
		memset(vis, 0, sizeof(vis));
		dfs(0, 0);
		printf("%d\n",ans);
	}
}