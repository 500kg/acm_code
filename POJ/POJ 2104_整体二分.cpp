#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 50;
const int inf = 0x3f3f3f3f;
struct node
{
	int x, y, k, pos, cnt;
	node() {}node(int _x, int _y, int _k, int _pos, int _cnt)
	{
		x = _x, y = _y, k = _k, pos = _pos, cnt = _cnt;
	}
}Q[maxn * 3], b1[maxn * 3], b2[maxn * 3];
int a[maxn], ans[maxn];
int n, m;
int c[maxn];
void add(int x, int val)
{
	while (x <= 1e5)
	{
		c[x] += val;
		x += x&(-x);
	}
}
int query(int x)
{
	int ans = 0;
	while (x)
	{
		ans += c[x];
		x -= x&(-x);
	}
	return ans;
}
int l1, r1;
void cnt(int l, int r, int L, int R)
{
	for (int i = l; i <= r; i++)
	{
		if (Q[i].k)
			Q[i].cnt = query(Q[i].y) - query(Q[i].x - 1);
		else if (Q[i].y <= R)
			add(Q[i].pos, 1);
	}
	for (int i = l; i <= r; i++)
	{
		if (!Q[i].k&&Q[i].y <= R)
			add(Q[i].pos, -1);
	}
	l1 = 0, r1 = 0;
	for (int i = l; i <= r; i++)
	{
		//	cout << l << ' ' << r <<' '<< Q[i].cnt << ' ' << Q[i].k << endl;
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
				b1[l1++] = Q[i];
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
	cout << l << ' ' << r << ' ' << L << ' ' << R << endl;
	if (L == R)
	{
		for (int i = l; i <= r; i++)
			if (Q[i].k)
				ans[Q[i].pos] = L;
		return;
	}
	int mid = (L + R) >> 1;
	cnt(l, r, L, mid);
	if (l1)divide(l, l + l1 - 1, L, mid);
	if (l + l1 <= r)divide(l + l1, r, mid + 1, R);
}
int main()
{
	cin >> n >> m;
	int len = 0;
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
		Q[++len] = node(i, a[i], 0, i, 0);
	}
	for (int i = 1, x, y, k; i <= m; i++)
	{
		scanf("%d%d%d", &x, &y, &k);
		Q[++len] = node(x, y, k, i, 0);
	}
	divide(1, len, 0, 1e5);
	for (int i = 1; i <= m; i++)
		printf("%d\n", ans[i]);
}