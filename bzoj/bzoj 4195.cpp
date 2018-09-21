#include<bits/stdc++.h>
using namespace std;
const int maxn = 1000050;
int fa[maxn];
vector<int>v;
int getfa(int x)
{
	if (x == fa[x])return x;
	return fa[x] = getfa(fa[x]);
}
void uni(int x, int y)
{
	fa[getfa(x)] = getfa(y);
}
bool same(int x, int y)
{
	return getfa(x) == getfa(y);
}
struct node
{
	int u, v, e;
}Q[maxn];
int getid(int x) { return lower_bound(v.begin(), v.end(), x) - v.begin() + 1; }
int main()
{
	int T; cin >> T; while (T--)
	{
		int n; cin >> n;
		for (int i = 0; i <= 2 * n; i++)fa[i] = i;
		v.clear();
		for (int i = 0; i < n; i++)scanf("%d%d%d", &Q[i].u, &Q[i].v, &Q[i].e), v.push_back(Q[i].u), v.push_back(Q[i].v);
		sort(v.begin(), v.end()); v.erase(unique(v.begin(), v.end()), v.end());
		for (int i = 0; i < n; i++)
		{
			if (Q[i].e == 0)continue;
			int l = getid(Q[i].u), r = getid(Q[i].v);
			uni(l, r);
		}
		int flag = 0;
		for (int i = 0; i < n; i++)
		{
			if (Q[i].e)continue;
			int l = getid(Q[i].u), r = getid(Q[i].v);
			if (same(l, r))flag = 1;
		}
		if (flag)cout << "NO" << endl;
		else cout << "YES" << endl;
	}
}