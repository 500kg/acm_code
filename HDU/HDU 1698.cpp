#include<bits/stdc++.h>
using namespace std;
const int maxn = 100000;
struct seg
{
	int l, r, n;
}T[maxn * 4];
void build(int l, int r, int k)
{
	if (l == r)
	{
		T[k].l = l;
		T[k].r = r;
		T[k].n = 1;
		return;
	}
	T[k].l = l;
	T[k].r = r;
	T[k].n = 1;
	int mid = (l + r) / 2;
	build(l, mid, 2 * k);
	build(mid + 1, r, 2 * k + 1);
}
void insert(int i, int l, int r, int m)
{
	if (T[i].n == m)return;
	if (T[i].l == l&&T[i].r == r)
	{
		T[i].n = m;
		return;
	}
	if (T[i].n != -1)
	{
		T[2 * i].n = T[2 * i + 1].n = T[i].n;
		T[i].n = -1;
	}
	int mid = (T[i].l + T[i].r) >> 1;
	if (l > mid)insert(2 * i + 1, l, r, m);
	else if (r <= mid)insert(2 * i, l, r, m);
	else
	{
		insert(2 * i, l, mid, m);
		insert(2 * i + 1, mid + 1, r, m);
	}
}
int search(int i)
{
	if (T[i].n != -1)
	{
		int ans = (T[i].r - T[i].l + 1)*T[i].n;
		return ans;
	}
	else
	{
		int ans = search(2 * i) + search(2 * i + 1);
		return ans;
	}

}
int main()
{
	int kase = 0;
	int T; cin >> T; while (T--)
	{
		int n, k;
		scanf("%d%d", &n, &k);
		build(1, n, 1);
	//	printf("Case %d: The total value of the hook is %d.\n",++kase, search(1));
		while (k--)
		{
			int x, y, m;
			scanf("%d%d%d", &x, &y, &m);
			insert(1, x, y, m);
		}
	//	cout << 'a' << endl;
		int ans = search(1);
		printf("Case %d: The total value of the hook is %d.\n", ++kase, ans);
	}
}