#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 50;
vector<int>v;
struct node
{
	int a, id;
	bool operator <(const node &b)
	{
		if (a == b.a)return id < b.id;
		return a > b.a;
	}
}a[maxn];
int n;
struct N
{
	int l, r, sum;
	int lm, rm;
	int len;
	N() {}
	N(int _sum, int _lm, int _rm, int _len,int _l,int _r)
	{	
		sum = _sum, lm = _lm, rm = _rm, len = _len;
		l = _l, r = _r;
	}
}T[maxn * 40];
int root[maxn];
int cnt = 0;
void update(int l, int r, int &x, int y, int pos)
{
	x = ++cnt;
	T[x] = T[y];
	if (l == r)
	{
		T[x].lm = 1, T[x].rm = 1;
		T[x].sum = 1;
		T[x].len = 1;
		return;
	}
	int mid = l + r >> 1;
	if (mid >= pos)update(l, mid, T[x].l, T[y].l, pos);
	else update(mid + 1, r, T[x].r, T[y].r, pos);
	T[x].len = T[T[x].l].len + T[T[x].r].len;
	T[x].sum = max(max(T[T[x].l].sum, T[T[x].r].sum), T[T[x].l].rm + T[T[x].r].lm);
	T[x].lm = T[T[x].l].lm == T[T[x].l].len ? T[T[x].l].lm + T[T[x].r].lm : T[T[x].l].lm;
	T[x].rm = T[T[x].r].rm == T[T[x].r].len ? T[T[x].r].rm + T[T[x].l].rm : T[T[x].r].rm;
	//	T[x].sum = max(T[x].sum, max(T[x].lm, T[x].rm));
}
N merge(N a1, N a2)
{
	N tmp;
	tmp.sum = max(a1.rm + a2.lm, max(a1.sum, a2.sum));
	tmp.lm = a1.lm + (a1.lm == a1.len ? a2.lm : 0);
	tmp.rm = a2.rm + (a2.rm == a2.len ? a1.rm : 0);
	tmp.len = a1.len + a2.len;
	return tmp;
}
N query(int l, int r, int rt, int L, int R)
{
//	cout << l << ' ' << r <<' '<<L<<' '<<R<<' '<<T[rt].sum<< endl;
	if (L <= l && r <= R)return T[rt];
	int mid = l + r >> 1;
	N N1=N(0,0,0,0,0,0), N2=N(0, 0, 0, 0, 0, 0);
	if (mid >= L)N1 = query(l, mid, T[rt].l, L, R);
	if (mid < R)N2 = query(mid + 1, r, T[rt].r, L, R);
	return merge(N1, N2);
}
bool ok(int P, int l, int r, int w)
{
	N Q = query(1, n, root[P], l, r);
	//	cout << a[P].a<<' '<<a[P].id << ' '<<P<<' ' << l << ' ' << r << ' ' << Q.sum << endl;
	return Q.sum >= w;
}
void debug(int x, int l, int r)
{
	cout << l << ' ' << r << ' ' << T[x].sum << endl;
	if (l == r)return;
	int mid = l + r >> 1;
	debug(T[x].l, l, mid);
	debug(T[x].r, mid + 1, r);
}
int main()
{
	T[0].len = 1;
	cin >> n;
	for (int i = 1; i <= n; i++)scanf("%d", &a[i].a), a[i].id = i;
	sort(a + 1, a + 1 + n);
	for (int i = 1; i <= n; i++)update(1, n, root[i], root[i - 1], a[i].id);
	int m; cin >> m; int l, r, w;
	int ans;
	//	debug(root[5], 1, n);
	while (m--)
	{
		scanf("%d%d%d", &l, &r, &w);
		int L = 1, R = n;
		ans = 0;
		while (L < R)
		{
			int mid = L + R >> 1;
			if (ok(mid, l, r, w))
				R = mid;
			else
				L = mid + 1;
		}
		printf("%d\n", a[L].a);
	}
}
