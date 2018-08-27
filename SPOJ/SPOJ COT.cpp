#include<bits/stdc++.h>
using namespace std;
vector<int>v;
const int maxn = 1e5 + 50;
int a[maxn];
struct node
{
	int l, r, sum;

}T[maxn * 40];
int root[maxn];
int cnt = 0;
vector<int>G[maxn];
int F[maxn];
int dep[maxn];
int p[maxn][30];
void build(int &root, int l, int r)
{
	root = ++cnt;
	T[root].sum = 0;
	if (l == r)return;
	int mid = (l + r) >> 1;
	build(T[root].l, l, mid);
	build(T[root].r, mid + 1, r);
}
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
int query(int L, int R, int LCA, int LCA_Fa, int l, int r, int k)
{
	if (l == r)return l;
	int sum = T[T[L].l].sum + T[T[R].l].sum - T[T[LCA].l].sum - T[T[LCA_Fa].l].sum;
	int mid = (l + r) >> 1;
	if (sum >= k)return query(T[L].l, T[R].l, T[LCA].l, T[LCA_Fa].l, l, mid, k);
	else return query(T[L].r, T[R].r, T[LCA].r, T[LCA_Fa].r, mid + 1, r, k - sum);
}
void dfs(int pos, int fa, int rua)
{
	F[pos] = fa;
	dep[pos] = dep[fa] + 1;
	p[pos][0] = fa;
	for (int i = 1; i <= 18; i++)p[pos][i] = p[p[pos][i - 1]][i - 1];
//	cout << pos << ' '<<fa << endl;
	update(1, rua, root[pos], root[fa], a[pos]);
//	cout << pos << ' ' << fa << endl;
	for (int i = 0; i < G[pos].size(); i++)
	{
		if (G[pos][i] == fa)continue;
		dfs(G[pos][i], pos, rua);
	}
}
int LCA(int x, int y)
{
	if (dep[x] > dep[y])x ^= y, y ^= x, x ^= y;
	if (dep[x] < dep[y])
	{
		int del = dep[y] - dep[x];
		for (int i = 0; i < 18; i++)
			if (del&(1 << i))y = p[y][i];
	}
	if (x != y)
	{
		for (int i = 17; i >= 0; i--)
		{
			if (p[x][i] != p[y][i])
				x = p[x][i], y = p[y][i];
		}
		x = p[x][0], y = p[y][0];
	}
	return x;
}
int n, m;
void go();
int main()
{
	cnt = 0;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)scanf("%d", &a[i]), v.push_back(a[i]);
	sort(v.begin(), v.end()), v.erase(unique(v.begin(), v.end()), v.end());
	for (int i = 1; i <= n; i++)a[i] = lower_bound(v.begin(), v.end(), a[i]) - v.begin() + 1;
	int rua = v.size(); int x, y;
//	build(root[0], 1, rua);
	for (int i = 1; i < n; i++)
	{
		scanf("%d%d", &x, &y);
		G[x].push_back(y);
		G[y].push_back(x);
	}
	dfs(1, 0, rua);
	
	int k;
	for (int i = 0; i < m; i++)
	{
		scanf("%d%d%d", &x, &y, &k);
		int lca = LCA(x, y);
		printf("%d\n", v[query(root[x], root[y], root[lca], root[F[lca]], 1, rua, k) - 1]);
	}
}
void go()
{
	cnt = 0;
	for (int i = 0; i <= n; i++)G[i].clear(); v.clear();
	
}//
