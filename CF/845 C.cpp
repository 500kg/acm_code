#include<bits/stdc++.h>
using namespace std;
struct node
{
	int l, r;
}a[200005];
int cmp(node a, node b)
{
	if (a.l == b.l)
		return a.r < b.r;
	return a.l < b.l;
}
vector<int >vis;
int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d%d", &a[i].l, &a[i].r);
	sort(a, a + n, cmp);
	int used = 1;
	for (int i = 0; i < n; i++)
	{
		int cnt = 0;
		for (int j = 0; j < vis.size(); j++)
		{
			if (vis[j] < a[i].l)
				vis.erase(vis.begin()+j);
			else cnt++;

		}
		if (cnt >= 2)
		{
			used = 0;
			break;
		}
		vis.push_back(a[i].r);
	}
	if (used)puts("YES");
	else puts("NO");
}