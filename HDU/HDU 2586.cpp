#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
#define CSL int T;cin>>T;while(T--)
const int maxn = 1e5 + 50;
vector<pair<int,int>>G[maxn];
int son[maxn];
int sz[maxn];
int fa[maxn];
int id[maxn];
int top[maxn];
int rk[maxn];
int d[maxn];
int dep[maxn];
int tot = 0;
void dfs1(int u, int f,int dis)
{
	d[u] = dis;
	son[u] = 0;
	dep[u] = dep[f] + 1;
	fa[u] = f;
	sz[u] = 1;
	for (int i=0;i<G[u].size();i++)
	{
		pair<int,int> v = G[u][i];
		if (v.first == f)continue;
		dfs1(v.first, u,v.second+dis);
		if (sz[v.first] > sz[son[u]])son[u] = v.first;
		sz[u] += sz[v.first];
	}
}
void dfs2(int u, int t)
{
	top[u] = t;
	id[u] = ++tot;
	rk[tot] = u;
	if (!son[u])return;
	dfs2(son[u], t);
	for (int i=0;i<G[u].size();i++)
	{
		pair<int, int> v = G[u][i];
		if (v.first != fa[u] && v.first != son[u])
			dfs2(v.first, v.first);
	}
}
int lca(int u, int v)
{
	int fu = top[u], fv = top[v];
	while (top[u] != top[v])
	{
		dep[top[u]] > dep[top[v]] ? u = fa[top[u]]:v = fa[top[v]];
	}
	return dep[u] < dep[v] ? u : v;
}int n, m;
;
void go()
{
	
	char ch[15];
	cin >> n >> m;
	int u, v, dis;
	for (int i = 0; i <= n; i++)G[i].clear();
	for (int i = 0; i < n-1; i++)
	{
		scanf("%d%d%d", &u, &v, &dis);
		G[u].push_back(make_pair(v,dis));
		G[v].push_back(make_pair(u, dis));
	}
	dfs1(1, 0, 0);
//	cout << "RUA" << endl;
	dfs2(1, 1);
	while (m--)
	{
		scanf("%d%d", &u, &v);
		printf("%d\n", d[u] + d[v] - 2 * d[lca(u, v)]);
	}
}
int main()
{
	CSL go();
}