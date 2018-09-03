#include<bits/stdc++.h>
using namespace std;
const int K = 2;
const int N = 1e5 + 50;
int idx, n, q, k = 2, f[N];

struct Node
{
	int x[K], id;
	bool operator < (const Node &u) const
	{
		for (int i = 0; i<k; i++)
			if (x[i] != u.x[i]) return x[i]<u.x[i];
		return 0;
	}
} P[N];

typedef pair<double, Node> PDN;
double sqr(double x) { return x * x; }
priority_queue<PDN> que;

bool cmp(const Node a, const Node b)
{
	return a.x[idx]<b.x[idx];
}

struct KD_Tree
{
	int sz[N << 2]; Node p[N << 2];

	void build(int i, int l, int r, int dep)
	{
		if (l>r) return;
		int mid = (l + r) >> 1;
		idx = dep % k; sz[i] = r - l;
		sz[i << 1] = sz[i << 1 | 1] = -1;
		nth_element(P + l, P + mid, P + r + 1, cmp);
		p[i] = P[mid];
		build(i << 1, l, mid - 1, dep + 1);
		build(i << 1 | 1, mid + 1, r, dep + 1);
	}

	void query(int i, int m, int dep, Node a)
	{
		if (sz[i] == -1) return;
		PDN tmp = PDN(0, p[i]);
		for (int j = 0; j<k; j++)
			tmp.first += sqr(tmp.second.x[j] - a.x[j]);
		int lc = i << 1, rc = i << 1 | 1, dim = dep % k, flag = 0;
		if (a.x[dim] >= p[i].x[dim]) swap(lc, rc);
		if (~sz[lc]) query(lc, m, dep + 1, a);
		if (tmp.first&&que.size()<m) que.push(tmp), flag = 1;
		else
		{
			if (tmp.first&&tmp<que.top()) que.pop(), que.push(tmp);
			if (sqr(a.x[dim] - p[i].x[dim]) <= que.top().first) flag = 1;
		}
		if (~sz[rc] && flag) query(rc, m, dep + 1, a);
	}

} KDT;
int find(int x){return f[x] == x ? x : f[x] = find(f[x]);}
void merge(int x, int y)
{
	int tx = find(x);
	int ty = find(y);
	if (tx != ty)f[tx] = ty;
}
bool same(int x, int y) { return find(x) == find(y); }
int kase = 0;
int main()
{
	int T; cin >> T; while (T--)
	{
		int n, q;
		scanf("%d%d", &n, &q);
		for (int i = 0; i <= n; i++)f[i] = i;
		for (int i = 0; i < n; i++)scanf("%d%d", &P[i].x[0], &P[i].x[1]), P[i].id = i;
		KDT.build(1, 0, n - 1, 0);
		for (int i = 0; i < n; i++)
		{
			que.push(PDN(1e19, P[i]));
			KDT.query(1, 1, 0, P[i]);
			Node tmp = que.top().second;
			merge(P[i].id, tmp.id);
			while (!que.empty())que.pop();
		}
		printf("Case #%d:\n", ++kase);
		int x, y;
		while (q--)
		{
			scanf("%d%d", &x, &y); x--, y--;
			if (same(x, y))
				printf("YES\n");
			else
				printf("NO\n");
		}
	}
}