#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 50;
const int inf = 1e9;
struct node
{
	int x, y, k, pos, cnt;
	node() {}node(int _x, int _y, int _z, int _pos, int _cnt)
	{
		x = _x, y = _y, k = _z, pos = _pos, cnt = _cnt;
	}
}Q[maxn * 3], b1[maxn * 3], b2[maxn * 3];
int a[maxn], ans[maxn], c[maxn];
int n, m;
void  add(int x, int val)
{
	for (int i = x; i <= n; i += i&-i)
		c[i] += val;
}
int query(int x)
{
	int ans = 0;
	while (x)
	{
		ans += c[x];
		x -= x&-x;
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
	if (L == R)
	{
		for (int i = l; i <= r; i++)
			if (Q[i].k)
				ans[Q[i].pos] = L;
		return;
	}
	int mid = L + R >> 1;
	cnt(l, r, L, mid);
	int tmp = l1;
	if (tmp)divide(l, l + tmp - 1, L, mid);
	if (l + tmp <= r)divide(l + tmp, r, mid + 1, R);
}
int main()
{
	int T; cin >> T; while (T--)
	{
		int len = 0;
	
		cin >> n >> m;
		for (int i = 1; i <= n; i++)
		{
			scanf("%d", &a[i]);
			Q[++len] = node(i, a[i], 0, 0, 1);
		}
		char ch[100];
		for (int i = 1, x, y, z; i <= m; i++)
		{
			scanf("%s", ch);
			if (ch[0] == 'Q')
			{
				scanf("%d%d%d", &x, &y, &z);
				Q[++len] = node(x, y, z, i, 0);
			}
			else
			{
				scanf("%d%d", &x, &y);
				Q[++len] = node(x, a[x], 0, 0, -1);
				Q[++len] = node(x, y, 0, 0, 1);
				a[x] = y;
				ans[i] = 0;
			}
		}
		divide(1, len, 0, inf);
		for (int i = 1; i <= m; i++)
			if (ans[i])
				printf("%d\n", ans[i]);
	}
}