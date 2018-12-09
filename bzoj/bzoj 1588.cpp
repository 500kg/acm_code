#include<iostream>
#include<cstdio>
#include<stdlib.h>
#include<algorithm>
using namespace std;

namespace T
{
	const int maxn = 1e5 + 50;
	struct treap
	{
		int l, r;
		int val, data;
		int sz, cnt;
	}a[maxn];
	int tot, root, n, INF = 0x3f3f3f3f;
	int New(int val)
	{
		a[++tot].val = val;
		a[tot].sz = a[tot].cnt = 1;
		a[tot].data = rand();
		a[tot].l = a[tot].r = 0;
		return tot;
	}
	void update(int p)
	{
		a[p].sz = a[a[p].l].sz + a[a[p].r].sz + a[p].cnt;
	}
	void build()
	{
		New(-INF), New(INF);
		root = 1;
		a[1].r = 2;
		update(root);
	}
	void zig(int &p)
	{
		int q = a[p].l;
		a[p].l = a[q].r, a[q].r = p, p = q;
		update(a[p].r), update(p);
	}
	void zag(int &p)
	{
		int q = a[p].r;
		a[p].r = a[q].l, a[q].l = p, p = q;
		update(a[p].r), update(p);
	}
	void Insert(int &p, int val)
	{
		if (p == 0)
		{
			p = New(val);
			return;
		}
		if (val == a[p].val)
		{
			a[p].cnt++, update(p);
			return;
		}
		if (val<a[p].val)
		{
			Insert(a[p].l, val);
			if (a[p].data<a[a[p].l].data)zig(p);
		}
		else if (val>a[p].val)
		{
			Insert(a[p].r, val);
			if (a[p].data<a[a[p].r].data)zag(p);
		}
		update(p);
	}
	int getpre(int val)
	{
		int ans = 1;
		int p = root;
		while (p)
		{
			if (val == a[p].val)
			{
				return val;
				if (a[p].l>0)
				{
					p = a[p].l;
					while (a[p].r>0)p = a[p].r;
					ans = p;
				}
				break;
			}
			if (a[p].val<val&&a[p].val>a[ans].val)ans = p;
			p = val<a[p].val ? a[p].l : a[p].r;
		}
		return a[ans].val;
	}
	int getnext(int val)
	{
		int ans = 2;
		int p = root;
		while (p)
		{
			if (val == a[p].val)
			{
				return val;
				if (a[p].r>0)
				{

					p = a[p].r;
					while (a[p].l>0)p = a[p].l;
					ans = p;
				}
				break;
			}
			if (a[p].val>val&&a[p].val<a[ans].val)ans = p;
			p = val<a[p].val ? a[p].l : a[p].r;
		}
		return a[ans].val;
	}
}

int main()
{
	T::build();
	int n; cin >> n;
	long long ans = 0, rua;
	for (int i = 0, x; i<n; i++)
	{
		scanf("%d", &x);
		if (i) rua = min(abs(T::getnext(x) - x), abs(T::getpre(x) - x));
		if (i) ans += rua;
		if (!i)ans += x;
		T::Insert(T::root, x);
	}
	cout << ans << endl;
}