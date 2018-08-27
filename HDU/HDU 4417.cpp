#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
const int maxn = 1e5 + 50;
typedef long long ll;
const int MOD = 998244353;
struct node
{
	int l, r;
	int sum;
}T[maxn * 40];
vector<int>v;
int a[maxn];
int root[maxn];
int cnt = 0;
int getid(int x) { return lower_bound(v.begin(), v.end(), x) - v.begin() + 1; }
void build(int &root,int l,int r)
{
	root = ++cnt;
	T[root].sum = 0;
	if (l == r)return;
	int mid = (l + r) >> 1;
	build(T[root].l, l, mid);
	build(T[root].r, mid + 1, r);
}

void update(int l, int r, int &root, int pre, int pos)
{
	root = ++cnt;
	T[root] = T[pre];
	T[root].sum++;
	if (l == r)return;
	int mid = (l + r) >> 1;
	if (mid >= pos)update(l, mid, T[root].l, T[pre].l, pos);
	else update(mid + 1, r, T[root].r, T[pre].r, pos);
}
int query(int l, int r, int x, int y, int k)
{
	if (l == r)return T[y].sum - T[x].sum;
	int sum = T[T[y].l].sum - T[T[x].l].sum;
	int mid = (l + r) >> 1;
	if (mid >= k)return query(l, mid, T[x].l, T[y].l, k);
	else return sum+query(mid + 1, r, T[x].r, T[y].r, k);
}
int main()
{
	int T;
	cin >> T;
	int kase = 0;
	while (T--)
	{
		int n, m;
		printf("Case %d:\n", ++kase);
		scanf("%d%d", &n, &m);
		v.clear();
		for (int i = 1; i <= n; i++)scanf("%d", &a[i]), v.push_back(a[i]);
		sort(v.begin(), v.end()), v.erase(unique(v.begin(), v.end()), v.end());
		cnt = 0; build(root[0], 1, n);
		for (int i = 1; i <= n; i++)
			update(1, n, root[i], root[i - 1], getid(a[i]));
		while (m--)
		{
			int l,r, k;
			scanf("%d%d%d", &l, &r, &k); l++, r++;
			k = upper_bound(v.begin(), v.end(), k) - v.begin();
	//		cout << "RUA " << k << endl;
			if(k)printf("%d\n", query(1, n, root[l - 1], root[r], k));
			else printf("0\n");
		}
	}
}
