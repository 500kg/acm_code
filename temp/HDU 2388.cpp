#include<bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
struct edge
{
	int to, cost;
};
typedef pair<int, int >P;
const int maxn = 1e4 + 50;
int v;
vector<edge>G[maxn];
int d[maxn];
int vis[maxn];
void dj(int s)
{
	memset(vis, 0, sizeof(vis));
	priority_queue<P, vector<P>, greater<P>>que;
	d[s] = 0;
	que.push(P(0, s));
	while (!que.empty())
	{
		P p = que.top();
		que.pop();
		int v = p.second;
		if (vis[v]) continue;
		vis[v] = 1;
		if (d[v] < p.first)continue;
		for (int i = 0; i < G[v].size(); i++)
		{
			edge e = G[v][i];
			if (!vis[e.to] && d[e.to] > d[v] + e.cost)
			{
				d[e.to] = d[v] + e.cost;
				que.push(P(d[e.to], e.to));
			}
		}
	}
}
int main()
{
	int T;
	cin >> T;
	int kase = 0;
	while (T--)
	{

		int n, m;

		scanf("%d%d", &n, &m);
		for (int i = 0; i <= n; i++)
			G[i].clear();
		fill(d, d + n + 5, INF);
		for (int i = 0; i < n; i++)
		{
			int x;
			scanf("%d", &x);
			edge e;
			e.to = i;
			e.cost = x;
			G[n].push_back(e);
		}
		for (int i = 1; i <= m; i++)
		{
			int a, b, x, y;
			scanf("%d%d%d%d", &a, &b, &x, &y);
			edge p;
			a, b;
			p.to = b; p.cost = x;
			G[a].push_back(p);
			p.to = a; p.cost = y;
			G[b].push_back(p);
		}
		dj(n);
		int cnt = 0;
		for (int i = 0; i < n; i++)
		{
			//	cout << d[i] << endl;
			if (d[cnt] < d[i])
				cnt = i;
		}
		printf("Scenario #%d:\n", ++kase);
		printf("%d\n\n", cnt);
	}
}