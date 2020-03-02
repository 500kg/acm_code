#include<bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 50;
char ch[maxn];
int a[maxn];
int ans[maxn];
struct node
{
	int p, pos, num;
	bool operator<(const node &a)const
	{
		return num < a.num;
	}
	node() {}node(int _p, int _pos, int _num)
	{
		p = _p, pos = _pos, num = _num;
	}
};
int vis[maxn];
int ne[maxn];
int main()
{
	int kase = 0;
	int T; cin >> T; while (T--)
	{
		int n; cin >> n;
		for (int i = 0; i < n; i++)ne[i] = (1LL*i*i + 1) % n;
		memset(vis, -1, sizeof(vis));
		memset(ans, -1, sizeof(ans));
		scanf("%s", ch);
		for (int i = 0; i < n; i++)a[i] = ch[i] - '0';
		int maxi = -1;
		for (int i = 0; i < n; i++)maxi = max(maxi, a[i]);
		priority_queue<node>q;
		for (int i = 0; i < n; i++)if (a[i] == maxi)q.push(node(0, i, maxi));
		while (!q.empty())
		{
			node now = q.top(); q.pop();
			if (ans[now.p] > now.num)continue;
			else ans[now.p] = now.num;
			if (vis[now.pos] < now.p)vis[now.pos] = now.p;
			else continue;
			if (now.p == n - 1)continue;
			q.push(node(now.p + 1, ne[now.pos], a[ne[now.pos]]));
		}
		printf("Case #%d: ", ++kase);
		for (int i = 0; i < n; i++)printf("%d", ans[i]);
		printf("\n");
	}
}