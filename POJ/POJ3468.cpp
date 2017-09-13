#include<cstring>
#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXN = 100000;
int num[MAXN];
struct seg
{
	int l, r;
	long long sum;
	long long add;
}T[MAXN * 3];
void build(int i, int l, int r)
{
	T[i].l = l;
	T[i].r = r;
	T[i].add = 0;
	if (l == r)
	{
		T[i].sum = num[l];
		return;
	}
	int mid = (l + r) >> 1;
	build(i << 1, l, mid);
	build(i << 1 | 1, mid + 1, r);
	T[i].sum = T[i << 1].sum + T[i << 1 | 1].sum;
}
void insert(int i, int a, int b, long long c)
{
	if (T[i].l == a&&T[i].r == b)
	{
		T[i].add += c;
		return;
	}
	T[i].sum += c*(b - a + 1);
	int mid = (T[i].l + T[i].r) >> 1;
	if (b <= mid)  insert(i << 1, a, b, c);
	else if(a>mid)  insert(i << 1 | 1, a, b, c);
	else
	{
		insert(i << 1, a, mid, c);
		insert(i << 1 | 1, mid + 1, b, c);
	}
}
long long search(int i, int a, int b)
{
	if (T[i].l == a&&T[i].r == b)
	{
		return T[i].sum + (b - a + 1)*T[i].add;
	}
	T[i].sum += (T[i].r - T[i].l + 1)*T[i].add;
	int mid = (T[i].l + T[i].r) >> 1;
	insert(i << 1, T[i].l, mid, T[i].add);
	insert(i << 1 | 1, mid + 1, T[i].r, T[i].add);
	T[i].add = 0;
	if (b <= mid)  return search(i << 1, a, b);
	else if(a>mid)  return search(i << 1 | 1, a, b);
	else return search(i << 1, a, mid) + search(i << 1 | 1, mid + 1, b);
}
int main()
{
	int n, q;
	while (scanf("%d%d", &n, &q) == 2)
	{
		for (int i = 1; i <= n; i++)  
			scanf("%d", &num[i]);
		build(1, 1, n);
		while(q--)
		{
			char ch;
			cin >> ch;
			if (ch == 'C')
			{
				int a, b, c;
				scanf("%d%d%d", &a, &b, &c);
				insert(1, a, b, c);
			}
			else
			{
				int a, b;
				scanf("%d%d", &a, &b);
				printf("%I64d\n", search(1, a, b));
			}
		}
	}
	return 0;
}