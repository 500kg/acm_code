#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
const int maxn = 1e5 + 50;
struct node
{
	int l, r, sum;
}T[maxn * 40];
vector<int>v;
int a[maxn];
int root[maxn];
int cnt;
int getid(int x) { return lower_bound(v.begin(), v.end(), x) - v.begin() + 1; }
void update(int l, int r, int &x, int y, int pos)
{
	x = ++cnt;
	T[x] = T[y];
	T[x].sum++;
	if (l == r)return;
	int mid = (l + r) >> 1;
	if (mid >= pos)update(l, mid, T[x].l, T[y].l, pos);
	else update(mid + 1, r, T[x].r, T[y].r, pos);
}
int query(int l, int r, int x, int y, int k)
{
	if (l == r)return l;
	int sum = T[T[y].l].sum - T[T[x].l].sum;
	int mid = (l + r) >> 1;
	if (sum >= k)return query(l, mid, T[x].l, T[y].l, k);
	else return query(mid + 1, r, T[x].r, T[y].r, k - sum);
}
int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)scanf("%d", &a[i]), v.push_back(a[i]);
	sort(v.begin(), v.end()), v.erase(unique(v.begin(), v.end()), v.end());
	for (int i = 1; i <= n; i++)update(1, n, root[i], root[i - 1], getid(a[i]));
	while (m--)
	{
		int l, r, k;
		scanf("%d%d%d", &l, &r, &k);
		printf("%d\n", v[query(1, n, root[l - 1], root[r], k) - 1]);
	}
}