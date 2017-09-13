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
int m, n;double ans;
void test()
{
	for (int i = 0; i < n; i++)
		printf("%d %d %.2f\n", a[i].a, a[i].b, a[i].c);
}
void solve()
{
	
	int i = 0;
	ans = 0;
	while (m&&i<n)
	{
		if (m >= a[i].b)
		{
			ans += a[i].a; 
			m -= a[i].b; i++;
		}
		else
		{
			ans += a[i].a*1.0 / a[i].b*m;
			m = 0; i++;
		}
	}
	printf("%.3f\n", ans);
}
int main()
{

	while (scanf("%d%d", &m, &n) == 2)
	{
		if (m == -1 && n == -1)break;
		for (int i = 0; i < n; i++)
		{
			cin >> a[i].a >> a[i].b; a[i].c = 1.0*a[i].a / a[i].b;
		}
		sort(a, a + n, cmp);            
	//	test();
		solve();
	}
	return 0;
}