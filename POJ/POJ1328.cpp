#include<iostream>
#include<stdio.h>
#include<math.h>
#include<algorithm>
using namespace std;
int  n;
double l;
int cas = 1;
struct xy
{
	double l, r;
}a[1005];
int cmp(xy a, xy b)
{
	return a.r < b.r||(a.r==b.r&&a.l>b.l);
}
void solve()
{
	sort(a, a + n, cmp);
	int ans = 1;
	double now = a[0].r;
	for (int i = 1; i < n; i++)
		if (a[i].l > now)now = a[i].r, ans++;
	printf("Case %d: %d\n", cas++, ans);
}
int main()
{

	while (scanf("%d%lf", &n, &l) == 2)
	{
		if (n == 0 && l == 0)break;
		int flag = 0; double x, y;
		for (int i = 0; i < n; i++)
		{
			scanf("%lf%lf", &x, &y);
			a[i].l = x + 0.0 - sqrt(l*l - y*y);
			a[i].r = x + 0.0 + sqrt(l*l - y*y);
			if (y > l)flag = 1;
		}
		if (flag)printf("Case %d: %d\n", cas++, -1);
		else  solve();
	}
	return 0;
}
