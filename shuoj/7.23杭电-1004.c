
#include<bits/stdc++.h>
using namespace std;
priority_queue<int, vector<int>, greater<int>> q;
queue<int>t;
struct node
{
	int l, r;
}a[100005];
int ans[100005];
int cmp(node a, node b)
{
	if (a.l == b.l)return a.r > b.r;
	return a.l < b.l;
}
int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		int n, m;
		cin >> n >> m;
		memset(ans, 0, sizeof(ans));
		while (!q.empty())q.pop();
		while (!t.empty())t.pop();
		for (int i = 0; i < m; i++)scanf("%d%d", &a[i].l, &a[i].r);
		sort(a, a + m, cmp);
		for (int i = 1; i <= n; i++)q.push(i);
		int prel = a[0].l, prer = a[0].r;
		for (int i = a[0].l; i <= a[0].r; i++)
		{
			int tmp = q.top(); q.pop();
			ans[i] = tmp;
			t.push(ans[i]);
		}
		for (int i = 1; i < m; i++)
		{
			if (a[i].r<=prer)continue;
			if (a[i].l > prer)
			{
				while (!t.empty())
				{
					q.push(t.front());
					t.pop();
				}
				for (int j = a[i].l; j <= a[i].r; j++)
				{
					ans[j] = q.top();
					q.pop();
					t.push(ans[j]);
				}
			}
			else
			{
				for (int j = prel; j < a[i].l; j++)
				{
					q.push(t.front()); t.pop();
				}
				for (int j = prer + 1; j <= a[i].r; j++)
				{
					ans[j] = q.top();
					t.push(ans[j]);
					q.pop();
				}
			}
			prer = a[i].r;
			prel = a[i].l;
		}
		int fir = 0;
		for (int i = 1; i <= n; i++)
		{
			if (fir)printf(" ");
			if (ans[i] == 0)ans[i] = 1;
			printf("%d", ans[i]);
			fir = 1;
		}printf("\n");
	}
}
