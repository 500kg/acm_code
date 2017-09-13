#include<iostream>
#include<stdio.h>
#include<math.h>
#include<algorithm>
#include<string.h>
using namespace std;int n;
struct ri
{
	int day, num;
}a[10005];
int vis[10005];
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
				vis[j] = 1;ans += a[i].num; break;
			}
		}

	}
	cout << ans << endl;
}
int main()
{
    while(cin >> n){
		for (int i = 0; i < n; i++)
			cin >> a[i].num>> a[i].day;
		solve();
	}
}