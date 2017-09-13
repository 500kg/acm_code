#include<bits/stdc++.h>
using namespace std;
int n, m;
struct bag
{
	int v, w;
}a[100];
bool cmp(struct bag a, struct bag b)
{
	return a.v > b.v;
}
void solve()
{
	sort(a, a + n, cmp);
	int i = 0;
	int ans = 0;
	while (m&&i<n)
	{
		if (m >= a[i].w)
		{
			m -= a[i].w;
			ans += a[i].w*a[i].v;
		}
		else
		{
			 ans += m*a[i].v; m = 0;
		}
		i++;
	}
	cout << ans << endl;
}
int main()
{
	int T; cin >> T; while (T--)
	{
		cin >> n >> m;
		for (int i = 0; i < n; i++)
			cin >> a[i].v >> a[i].w;
		solve();
	}
}