#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
const int maxn = 2e5 + 50;
vector<int>G[maxn];
int sz[maxn];
int n, k;
void dfs1(int u, int fa)
{
	sz[u] = 1;
	for (auto &v : G[u])
	{
		if (v == fa)continue;
		dfs1(v, u);
		sz[u] += sz[v];
	}
}
int ans = 0;
void dfs2(int u, int fa)
{
//	cout << n << ' ' << sz[u] <<' '<<n-sz[u]<<' '<<k<< endl;
	if (sz[u] >= k && (n - sz[u] >= k))ans++;
	for (auto &v : G[u])
	{
		if (v != fa)dfs2(v, u);
	}
}
int main()
{
	int T; cin >> T; while (T--)
	{
		scanf("%d%d", &n, &k);
		for (int i = 0; i <= n; i++)G[i].clear();
		for (int i = 1, u, v; i < n; i++)
		{
			scanf("%d%d", &u, &v);
			G[u].push_back(v);
			G[v].push_back(u);
		}
		dfs1(1, 0);
		ans = 0;
		dfs2(1, 0);
		printf("%d\n", ans);
	}

}