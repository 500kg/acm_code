#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <queue>
#include <map>
#include <vector>
#include <set>
#include <string>
#include <math.h>
using namespace std;
struct point
{
	int x, y;
	point() {}
	point(int _x, int _y)
	{
		x = _x, y = _y;
	}
	point operator -(const point &b)const
	{
		return point(x - b.x, y - b.y);
	}
	point operator +(const point &b)const
	{
		return point(x + b.x, y + b.y);
	}
	int operator *(const point &b)const
	{
		return x*b.x + y*b.y;
	}
	int operator ^(const point &b)const
	{
		return x*b.y - y*b.x;
	}
};
struct line
{
	point s, e;
	line() {}
	line(point _s, point _e)
	{
		s = _s; e = _e;
	}
};
int xmult(point p0, point p1, point p2)
{
	return (p1 - p0) ^ (p2 - p0);
}
const int maxn = 5050;
line lin[maxn];
int ans[maxn];
int cmp(line a, line b)
{
	return a.s.x < b.s.x;
}
int main()
{
	int n, m, x1, x2, y1, y2;
	while (scanf("%d", &n) == 1 && n)
	{
		scanf("%d%d%d%d%d", &m, &x1, &y1, &x2, &y2);
		int Ui, Li;
		for (int i = 0; i < n; i++)
		{
			scanf("%d%d", &Ui, &Li);
			lin[i] = line(point(Ui, y1), point(Li, y2));
		}
		lin[n] = line(point(x2, y1), point(x2, y2));
		sort(lin, lin + n + 1, cmp);
		int x, y;
		memset(ans, 0, sizeof(ans));
		point p;
		while (m--)
		{
			scanf("%d%d", &x, &y);
			p = point(x, y);
			int l = 0, r = n;
			int tmp;
			while (l <= r)
			{
				int mid = (l + r) / 2;
				if (xmult(p, lin[mid].s, lin[mid].e) < 0)
				{
					tmp = mid;
					r = mid - 1;
				}
				else l = mid + 1;
			}
			ans[tmp]++;
		}
		int num[maxn];
		memset(num, 0, sizeof(num));
		for (int i = 0; i <= n; i++)
			if (ans[i])
				num[ans[i]]++;
		puts("Box");
		for (int i = 1; i <= n; i++)
			if (num[i])
				printf("%d: %d\n", i, num[i]);

	}
	return 0;
}