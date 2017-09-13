#include<bits/stdc++.h>
using namespace std;
const int maxn = 100100;
struct seg
{
	int l, r;
	long long sum;
}T[maxn*4];
void build(int l, int r, int i)
{
	T[i].l = l;
	T[i].r = r;
	if (l == r)
	{
		scanf("%lld", &T[i].sum);
		return;
	}
	int mid = (l + r) >> 1;
	build(l, mid, i << 1);
	build(mid + 1, r, i << 1 | 1);
	T[i].sum = T[i << 1].sum + T[i << 1 | 1].sum;
}
void action(int l, int r, int i)
{
	if (T[i].l == l&&T[i].r == r&&T[i].sum == (r - l + 1))
		return;
	if (T[i].l == T[i].r)
	{
		T[i].sum = sqrt(T[i].sum*1.0);
		return;
	}
	int mid = (T[i].l + T[i].r) >> 1;
	if (r <= mid)action(l, r, i << 1);
	else if (l > mid)action(l, r, i << 1 | 1);
	else
	{
		action(l, mid, i << 1);
		action(mid + 1, r, i << 1 | 1);
	}
	T[i].sum = T[i << 1].sum + T[i << 1 | 1].sum;
}
long long sum(int l, int r, int i)
{
	if (l == T[i].l&&r == T[i].r)
		return T[i].sum;
	long long ans= 0;
	int mid = (T[i].l + T[i].r) >> 1;
	if (r <= mid)ans = sum(l, r, i << 1);
	else if (l > mid)ans = sum(l, r, i << 1 | 1);
	else
	{
		ans += sum(l, mid, i << 1);
		ans += sum(mid + 1, r, i << 1 | 1);
	}
	return ans;
}
int main()
{
	int n;
	int kase = 0;
	while (scanf("%d", &n) == 1)
	{
		printf("Case #%d:\n", ++kase);
		build(1, n, 1);
		int T;
		cin >> T;
		while (T--)
		{
			int a, b, c;
			scanf("%d%d%d", &a, &b, &c);
			if (b > c)swap(b, c);
			if (a == 0)
			{
				action(b, c, 1);
			}
			else
			{
				cout << sum(b, c, 1) << endl;
			}
		}
		puts("");
	}

}