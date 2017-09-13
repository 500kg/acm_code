#include<bits/stdc++.h>
using namespace std;
struct node
{
	int d, s, e;
}a[50005];
int cmp(node a, node b)
{
	if (a.d == b.d)
	{
		return a.e < b.e;
	}return a.d < b.d;
}
int main()
{
	int T;
	cin >> T;
	int kase = 0;
	while (T--)
	{
		int n;
		cin >> n;
		for (int i = 0; i < n; i++)
			scanf("%d%d%d", &a[i].d, &a[i].s, &a[i].e);
		sort(a, a + n, cmp);
	/*	puts("RUA");
		for (int i = 0; i < n; i++)
			printf("%d %d %d\n", a[i].d, a[i].s, a[i].e);
	*/	int cnt = 0;
		int nowd = -1, nowt = -1;
		for (int i = 0; i < n; i++)
		{
			if (nowd != a[i].d)
			{
				nowt = -1;
				nowd = a[i].d;
			}
			if (a[i].s >= nowt)
			{
				cnt++;
				nowt = a[i].e;
			}
		}
		printf("Scenario #%d:\n", ++kase);
		printf("%d\n\n", cnt);
	}
}