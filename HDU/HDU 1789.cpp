#include<bits/stdc++.h>
using namespace std;int n;
struct ri
{
	int day, num;
}a[1005];
int vis[1005];
int cmp(ri a,ri b)
{
	if (a.num == b.num)
		return a.day < b.day;
	else return a.num > b.num;  
}
void solve()
{
	sort(a, a + n, cmp);
	memset(vis, 0, sizeof(vis));
	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		int j;
		for (j = a[i].day; j > 0; j--)
		{
			if (!vis[j])
			{
				vis[j] = 1; break;
			}
		}
			if (j == 0)ans += a[i].num;
		
	}
	cout << ans << endl;
}
int main()
{
	int T; cin >> T; while (T--)
	{
		cin >> n;
		for (int i = 0; i < n; i++)
			cin >> a[i].day;
		for (int i = 0; i < n; i++)
			cin >> a[i].num;
		solve();
	}
}