#include<bits/stdc++.h>
using namespace std;
const int maxn = 3e4 + 50;
vector<int>v;
int a[maxn];
struct node
{
	int l, r, sum;
}T[maxn*40];
int root[maxn];
int vis[maxn];
int cnt = 0;
int getid(int x) { return lower_bound(v.begin(), v.end(), x) - v.begin() + 1; }
void update(int l, int r, int &x, int y, int pos,int val)
{
	x = ++cnt;
	T[x] = T[y];
	T[x].sum += val;
	if (l == r)return;
	int mid = l + r >> 1;
	if (mid >= pos)update(l, mid, T[x].l, T[y].l, pos, val);
	else update(mid + 1, r, T[x].r, T[y].r, pos, val);
}
int query(int root, int l, int r, int pos)
{
	if (l == r)return T[root].sum;
	int mid = (l + r) >> 1;
	if (mid >= pos)return T[T[root].r].sum + query(T[root].l, l, mid, pos);
	else return query(T[root].r, mid + 1, r, pos);
}
int main()
{
	int n, m;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)scanf("%d", &a[i]), v.push_back(a[i]);
	sort(v.begin(), v.end()), v.erase(unique(v.begin(), v.end()), v.end());
	for (int i = 1; i <= n; i++)a[i] = getid(a[i]);
	for (int i = 1; i <= n; i++)
	{
		if(!vis[a[i]])
			update(1, n, root[i], root[i - 1], i, 1);
		else
		{
			int tmp;
			update(1, n, tmp, root[i - 1], vis[a[i]], -1);
			update(1, n, root[i], tmp,i , 1);
		}
		vis[a[i]] = i;
	}
	scanf("%d", &m); int l, r;
	while (m--)
	{
		scanf("%d%d", &l, &r);
		printf("%d\n", query(root[r], 1, n, l));
	}
}
