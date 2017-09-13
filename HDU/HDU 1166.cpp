#include<bits/stdc++.h>
using namespace std;
struct seg
{
	int l, r, n;
}T[150011];
void build(int l, int r, int k)
{
	int mid;
	if (l == r)
	{
		T[k].l = l;
		T[k].r = r;
		T[k].n = 0;
		return;
	}
	T[k].l = l;
	T[k].r = r;
	T[k].n = 0;
	mid = (l + r) / 2;
	build(l, mid, 2 * k);
	build(mid + 1, r, 2 * k + 1);
}
void insert(int n, int d, int k)
{
	int mid;
	if (T[k].l == T[k].r&&T[k].l == d)
	{
		T[k].n += n;
		return;
	}
	mid = (T[k].l + T[k].r) >> 1;
	if (d <= mid)insert(n, d, 2 * k);
	else insert(n, d, 2 * k + 1);
	T[k].n = T[2 * k].n + T[2 * k + 1].n;
}
int ans;
void search(int l, int r, int k)
{
	if (T[k].l == l&&T[k].r==r)
	{
		ans += T[k].n;
		return;
	}
	int mid = (T[k].l + T[k].r) >> 1;
	if (r <= mid)search(l, r, 2 * k);
	else if(l>mid)search(l, r, 2 * k + 1);
	else
	{
		search(l, mid, 2 * k);
		search(mid + 1, r, 2 * k + 1);
	}

}
int main()
{
	int kase = 0;
	int T;
	cin >> T;
	while (T--)
	{
		int n;
		scanf("%d", &n);
		build(1, n, 1);
		for (int i = 1; i <= n; i++)
		{
			int tmp;
			scanf("%d", &tmp);
			insert(tmp, i, 1);
		}
		printf("Case %d:\n", ++kase);
		char str[11];
		while (scanf("%s", str), strcmp(str, "End"))
		{
			int a, b;
			scanf("%d%d", &a, &b);
			if (str[0] == 'A')insert(b, a, 1);
			else if (strcmp(str,"Sub")==0)insert(-b, a, 1);
			else
			{
				ans = 0;
				search(a, b, 1);
				printf("%d\n", ans);

			}
		}
	}
	return 0;
}