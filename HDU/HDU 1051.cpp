#include<bits/stdc++.h>
using namespace std;
struct sti
{
	int l, w;
}a[5005];
int n, vis[5005];
int cmp(sti a,sti b)
{
	if (a.l < b.l)return 1;
	else if (a.l == b.l&&a.w <= b. w)return 1;
	return 0;
}
void solve()
{
	memset(vis, 0, sizeof(vis));
	sort(a, a + n, cmp);
	int T = n;
	int ans = 0;
	while (T)
	{
		ans++;
		int nl = 0, nw = 0;
		for (int i = 0; i < n; i++)
			if (!vis[i] && a[i].l >= nl&&a[i].w >= nw)
			{
				vis[i] = 1, T--, nl = a[i].l, nw = a[i].w;
			}
	}
	cout << ans << endl;
}
int main()
{
	int T; cin >> T; while (T--)
	{

		cin >> n;
		for (int i = 0; i < n; i++)
			cin >> a[i].l >> a[i].w;
		solve();
	}
}