#include<bits/stdc++.h>
using namespace std;
struct node
{
	int a, b;
	double c;
}a[1005];
int cmp(node a, node b)
{
	return a.c > b.c;
}
int m, n;
void solve()
{
	sort(a, a + n, cmp);
	double ans;
	int i = 0;
	while (m)
	{
		if (m >= a[i].c)
		{
			ans += a[i].a;
		}
		else
		{
			ans += a[i].a*m / a[i].b;
		}
	}
	cout << ans << endl;
}
int main()
{
	
	while (scanf("%d%d", &m, &n) == 2)
	{
		for (int i = 0; i < n; i++)
		{
			cin >> a[i].a >> a[i].b; a[i].c = a[i].a / a[i].b*1.0;
		}
		solve();
	}
}