#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 50;
#define lson rt<<1
#define rson rt<<1|1
const int MOD = 1e9 + 7;
struct node
{
	int sum, len;
	node() {}node(int _sum,int _len)
	{
		sum = _sum, len = _len;
}
}T[maxn << 2];
void build(int rt, int l, int r)
{
	T[rt].sum = T[rt].len = 0;
	if (l == r)return;
	int mid = l + r >> 1;
	build(lson, l, mid);
	build(rson, mid + 1, r);
}
void pushup(int rt,int l,int r)
{
//	int l = lson, r = rson;
	if (T[l].len == T[r].len)
		T[rt].sum = T[l].sum + T[r].sum, T[rt].len = T[l].len;
	else
	{
		if (T[l].len < T[r].len)
			T[rt].sum = T[r].sum, T[rt].len = T[r].len;
		else
			T[rt].sum = T[l].sum, T[rt].len = T[l].len;
	}
	T[rt].sum %= MOD;
}
void update(int rt, int l, int r, int sum, int len, int pos)
{
	if (l == r)
	{
	//	cout <<"update: "<< l << ' ' << sum << ' ' << len <<' '<<pos<< endl;
		if (T[rt].len < len)T[rt].len = len, T[rt].sum = sum;
		else T[rt].sum += sum;
		T[rt].sum %= MOD;
		return;
	}
	int mid = l + r >> 1;
	if (mid >= pos)update(lson, l, mid, sum, len, pos);
	else update(rson, mid + 1, r, sum, len, pos);
	pushup(rt,lson,rson);
//	cout << l << ' ' << r << ' ' << T[rt].len << ' ' << T[rt].sum << endl;
}
node push(node a, node b)
{
	node ret;
	if (a.len == b.len)ret.len = a.len, ret.sum = (a.sum + b.sum) % MOD;
	else if (a.len < b.len)ret.len = b.len, ret.sum = b.sum;
	else ret.len = a.len, ret.sum = a.sum;
//	cout << ret.len << ' ' << ret.sum << ' ' << a.len << ' ' << a.sum << ' ' << b.len << ' ' << b.sum << endl;
	return ret;
}
node query(int rt, int l, int r, int L, int R)
{
//	cout << l << ' ' << r <<' '<<L<<' '<<R<< endl;
	if (L <= l&&r <= R)return T[rt];
	int mid = l + r >> 1;
	node a=node(0,0), b=node(0,0), ret;
	if (mid >= L)a = query(lson, l, mid, L, R);
	if (mid < R)b = query(rson, mid + 1, r, L, R);
//	cout << L << ' ' << R << ' '<<l<<' '<<r<<' ' << a.sum << ' ' << a.len << ' ' << b.sum << ' ' << b.len << endl;
	return push( a, b);
}
vector<int>v; int n, a[maxn];
int getid(int x) { return lower_bound(v.begin(), v.end(), x) - v.begin() + 1; }
void debug(int rt, int l, int r, int pos)
{
	cout << T[rt].sum << ' ' << T[rt].len << ' ' << l << ' ' << r << endl;
	int mid = l + r >> 1;
	if (l == r)return;
	if (mid >= pos)debug(lson, l, mid, pos);
	else debug(rson, mid + 1, r, pos);
}
int main()
{
	while (cin >> n)
	{
		v.clear();
		for (int i = 1; i <= n; i++)scanf("%d", &a[i]), v.push_back(a[i]);
		sort(v.begin(), v.end());
		v.erase(unique(v.begin(), v.end()), v.end());
		build(1, 1, n);
		for (int i = 1; i <= n; i++)
		{
			int id = getid(a[i]);
			node c;
			if (id > 1)
				c = query(1, 1, n, 1, id - 1);
			else
				c = node(1, 0);
			c.sum = max(1, c.sum);
		//	cout << "YYY" << endl;
	//		cout << i << ' ' << a[i] << ' ' << c.sum << ' ' << c.len << endl;
			update(1, 1, n, c.sum, c.len + 1, id);
			c = query(1, 1, n, 1, id);
		//	cout << c.sum << ' ' << c.len << endl;
		}
	//	debug(1, 1, n, 3);
		node c = query(1, 1, n, 1, n);
		cout << c.sum << endl;
	}
}