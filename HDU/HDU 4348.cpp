#include<bits/stdc++.h>
using namespace std;
const int maxn = 100002;
typedef long long ll;
struct node
{	
	int l, r;
	ll sum, add;
}T[maxn * 40];
int root[maxn];
int cnt;
void build(int &root, int l, int r)
{
	root = ++cnt;
	T[root].add = 0;
	if (l == r)
	{
		scanf("%lld", &T[root].sum);
	//	T[root].add = 0;
		return;
	}
	int mid = (l + r) >> 1;
	build(T[root].l, l, mid);
	build(T[root].r, mid + 1, r);
	T[root].sum = T[T[root].l].sum + T[T[root].r].sum;
}
void pushup(int x, int m)
{
	T[x].sum = T[T[x].l].sum + T[T[x].r].sum + 1LL * m*T[x].add;
}
void update(int l, int r, int &x, int y,int L,int R, int add)
{
	x = ++cnt;
	T[x] = T[y];
	if (L <= l&&r <= R)
	{
		T[x].add += add;
		T[x].sum += 1LL * add*(r - l + 1);
		return;
	}
	int mid = (l + r) >> 1;
	if (L <= mid)update(l, mid, T[x].l, T[y].l, L, R, add);
	if(mid<R) update(mid + 1, r, T[x].r, T[y].r, L, R, add);
	pushup(x, r - l + 1);
}
ll query(int l, int r, int x, int L, int R,int add)
{
	if (L <= l&&r <= R)
	{
		return T[x].sum + 1LL*(r - l + 1)*add;
	}
	add += T[x].add;
	int mid = (l + r) >> 1;
	ll ans = 0;
	if (L <= mid)ans += query(l, mid, T[x].l, L, R, add);
	if (R > mid)ans += query(mid + 1, r, T[x].r, L, R, add);
	return ans;
}
int main()
{
	int T;
	int n, m;
	int flag = 0;
	while (scanf("%d%d", &n, &m)==2)
	{
		if (flag)puts(""); flag = 1;
		int l, r, d;
		cnt = 0;
		build(root[0], 1, n);	
		int Tick = 0;
		for (int i = 1; i <= m; i++)
		{
			string c; cin >> c;
			if (c[0] == 'C')
			{
				scanf("%d%d%d", &l, &r, &d);
				++Tick;
				update(1, n, root[Tick], root[Tick - 1], l, r, d);
			}
			else if (c[0] == 'Q')
			{
				scanf("%d%d", &l, &r);
				printf("%lld\n", query(1, n, root[Tick], l, r, 0));
			}
			else if (c[0] == 'H')
			{
				scanf("%d%d%d", &l, &r, &d);
				printf("%lld\n", query(1, n, root[d], l, r, 0));
			}
			else
			{
				scanf("%d", &Tick);
				cnt = root[Tick+1] - root[0];
			}
		}
	}
}