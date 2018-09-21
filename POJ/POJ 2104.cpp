#include<vector>
#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn = 1e5 + 50;
vector<int>v;
struct node
{
	int l, r, sum;
}T[maxn * 40];
int root[maxn], tot;
void update(int l, int r, int &x, int y, int pos)
{
	x = ++tot;
	T[x] = T[y];
	T[x].sum++;
	if (l == r)return;
	int mid = l + r >> 1;
	if (mid >= pos)update(l, mid, T[x].l, T[y].l, pos);
	else update(mid + 1, r, T[x].r, T[y].r, pos);
}
int query(int l, int r, int x, int y, int k)
{
//	cout << l << ' ' << r << ' ' << k << ' '<<T[T[x].l].sum<<' '<<T[T[y].l].sum<< endl;
	if (l == r)return l;
	int mid = l + r >> 1;
	int sum = T[T[y].l].sum - T[T[x].l].sum;
	if (sum >= k)return query(l, mid, T[x].l, T[y].l, k);
	else return query(mid + 1, r, T[x].r, T[y].r, k - sum);
}
int a[maxn];
int getid(int x) { return lower_bound(v.begin(), v.end(), x) - v.begin() + 1; }
int main()
{
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)scanf("%d", &a[i]), v.push_back(a[i]);
	sort(v.begin(), v.end()); v.erase(unique(v.begin(), v.end()), v.end());
//	for (int i = 1; i <= n; i++)a[i] = getid(a[i]);
	for (int i = 1; i <= n; i++)
		update(1, n, root[i], root[i - 1], getid(a[i]));
	int l, r, k;
	while (m--)
	{
		scanf("%d%d%d", &l, &r, &k);
		printf("%d\n", v[query(1, n, root[l-1], root[r], k)-1]);
	}
}