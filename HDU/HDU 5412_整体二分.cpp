#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 50;
const int inf = 1e9;
struct node
{
	int x, y, k, cnt, pos;
	node() {}node(int _x, int _y, int _k, int _cnt, int _pos)
	{
		x = _x, y = _y, k = _k, cnt = _cnt, pos = _pos;
	}
}Q[maxn * 3], b1[maxn * 3], b2[maxn * 3];
int a[maxn], c[maxn], ans[maxn];
int n;
void add(int x,int val)
{
	for (int i = x; i <= n; i += (i&(-i)))
		c[i] += val;
}
int query(int x)
{
//	cout << "RUA" << endl;
	int ret = 0;
	for (int i = x; i; i -= (i&(-i)))
		ret += c[i];
	return ret;
}
int l1, r1;
void cnt(int l, int r, int L, int R)
{
	for (int i = l; i <= r; i++)
	{
		if (Q[i].k)
			Q[i].cnt = query(Q[i].y) - query(Q[i].x - 1);
		else if (Q[i].y <= R)
			add(Q[i].x, Q[i].cnt);
	}
	for (int i = l; i <= r; i++)
		if (!Q[i].k&&Q[i].y <= R)
			add(Q[i].x, -Q[i].cnt);
	l1 = 0, r1 = 0;
	for (int i = l; i <= r; i++)
	{
		if (Q[i].k)
		{
			if (Q[i].k <= Q[i].cnt)
				b1[l1++] = Q[i];
			else
			{
				Q[i].k -= Q[i].cnt;
				b2[r1++] = Q[i];
			}
		}
		else
		{
			if (Q[i].y <= R)
				b1[l1++]=Q[i];
			else
				b2[r1++] = Q[i];
		}
	}
	int now = l;
	for (int i = 0; i < l1; i++)Q[now++] = b1[i];
	for (int i = 0; i < r1; i++)Q[now++] = b2[i];
}
void divide(int l, int r, int L, int R)
{
//	cout << l << ' ' << r << ' ' << L << ' ' << R << endl;
	if (L == R)
	{
		for (int i = l; i <= r; i++)
			if (Q[i].k)
				ans[Q[i].pos] = L;
		return;
	}
	int mid = (L + R) >> 1;
	cnt(l, r, L, mid);
	int tmp = l1;
	if (tmp)
		divide(l, l + tmp - 1, L, mid);
	if (l + tmp <= r)
		divide(l + tmp, r, mid + 1, R);
}
int main()
{
	
	while (scanf("%d",&n)!=EOF)
	{
//		init();
	//	memset(c, 0, sizeof(c));
		int len = 0;
		for (int i = 1; i <= n; i++)
		{
			scanf("%d", &a[i]);
			Q[++len] = node(i, a[i], 0, 1, 0);
		}
		int m; scanf("%d", &m);
		for (int i = 1, x, y, k, op; i <= m; i++)
		{
			scanf("%d", &op);
			if (op == 1)
			{
				scanf("%d%d", &x, &y);
				Q[++len] = node(x, a[x], 0, -1, 0);
				Q[++len] = node(x, y, 0, 1, 0);
				ans[i] = 0;
				a[x] = y;
			}
			else
			{
				scanf("%d%d%d", &x, &y, &k);
				Q[++len] = node(x, y, k, 0, i);
				ans[i] = 0;
			}
		}
		divide(1, len, 1, inf);
		for (int i = 1; i <= m; i++)
			if (ans[i])
				printf("%d\n", ans[i]);
	}
	return 0;
}