#include<bits/stdc++.h>
using namespace std;
char ma[5][5];
int vis[5][5];
int ans, n;
int check(int x, int y)
{
	if (ma[x][y] != '.')return 0;
	for (int i = x; i >=0; i--)
	{
		if (ma[i][y] == 'X')break;
		if (vis[i][y] == 1)return 0;
	}
	for (int i = y; i >= 0; i--)
	{
		if (ma[x][i] == 'X')break;
		if (vis[x][i] == 1)return 0;
	}
	return 1;
}
void dfs(int pos,int cnt)
{
	if (pos == n*n) 
	{
		ans = max(ans, cnt);
		return;
	}
	int x = pos%n, y = pos / n;
	if (check(x, y))
	{
		vis[x][y] = 1;
		dfs(pos + 1, cnt + 1);
		vis[x][y] = 0;
	}
	dfs(pos + 1, cnt);
}
int main()
{
	//int n;
	while (scanf("%d", &n) == 1 && n)
	{
		memset(vis, 0, sizeof(vis));
		ans = 0;
		for (int i = 0; i < n; i++)
			scanf("%s", &ma[i]);
		dfs(0, 0);
		cout << ans << endl;
	}
}