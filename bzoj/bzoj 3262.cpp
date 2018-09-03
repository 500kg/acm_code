#include<bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 50;
struct node
{
	int x, y, z, id;
	node() {}node(int _x, int _y, int _z, int _id)
	{
		x = _x, y = _y, z = _z, id = _id;
	}
	bool operator ==(const node &a)
	{
		return x == a.x&&y == a.y&&z == a.z;
	}
}a[maxn], b[maxn];
int n, m;
bool cmp(const node &a, const node &b)
{
	if (a.x != b.x)return a.x < b.x;
	if (a.y != b.y)return a.y < b.y;
	if (a.z != b.z)return a.z < b.z;
	return a.id < b.id;
}
bool cmp2(const node &a, const node &b)
{
	if (a.y != b.y)return a.y < b.y;
	return a.id < b.id;
}
int ans[maxn], c[maxn];
int lowbit(int x)
{
	return x&(-x);
}
void add(int x, int val)
{
	for (int i = x; i <= m; i+=lowbit(i))
		c[i] += val;
}
int query(int x)
{
	int ans = 0;
	while (x)
	{
		ans += c[x];
		x -= lowbit(x);
	}
	return ans;
}
void cdq(int l, int r)
{
	if (l == r)return;
	int mid = l + r >> 1;
	cdq(l, mid); cdq(mid + 1, r);
	int now = 0;
	for (int i = l; i <= mid; i++)b[now++] = node(0, a[i].y, a[i].z, 0);
	for (int i = mid + 1; i <= r; i++)b[now++] = node(0, a[i].y, a[i].z, a[i].id);
	sort(b, b + now, cmp2);
	for (int i = 0; i < now; i++)
	{
		if (b[i].id)ans[b[i].id] += query(b[i].z);
		else add(b[i].z, 1);
	}
	for (int i = 0; i < now; i++)
		if (!b[i].id)add(b[i].z, -1);
}
int cnt[maxn * 2];
int main()
{
	cin >> n >> m; m += 50;
	for (int i = 1; i <= n; i++)scanf("%d%d%d", &a[i].x, &a[i].y, &a[i].z), a[i].id = i;
	sort(a + 1, a + 1 + n, cmp);
	for (int i = n, num = 0; i >= 1; i--)
	{
		if (a[i] == a[i + 1])num++;
		else num = 0;
		ans[a[i].id] += num;
	}
	cdq(1, n);
	int maxi = 0;
	for (int i = 1; i <= n; i++)cnt[ans[i]]++, maxi = max(maxi, ans[i]);
//	for (int i = 1; i <= n; i++)printf("%d\n", ans[i]);
	for (int i = 0; i < n; i++)printf("%d\n", cnt[i]);
}