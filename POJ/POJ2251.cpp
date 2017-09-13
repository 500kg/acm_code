#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<queue>
using namespace std;
int sx, sy, sz;
int ex, ey, ez;
int k, n, m;
char ma[35][35][35];
int vis[35][35][35];
int fx[6][3] = { { 1,0,0 },{ -1,0,0 },{ 0,1,0 },{ 0,-1,0 },{ 0,0,1 },{ 0,0,-1 } };
struct node
{
	int x, y, z, step;
};
bool check(node a)
{
	if (a.x >= 0 && a.y >= 0 && a.z >= 0 && a.x < k&&a.y < n&&a.z < m&&ma[a.x][a.y][a.z] != '#' && !vis[a.x][a.y][a.z])
		return true;
	return false;
}
int bfs()
{
	queue<node>q;
	node a, next;
	a.x = sx, a.y = sy, a.z = sz;
	a.step = 0;
	vis[a.x][a.y][a.z] = 1;
	q.push(a);
	while (!q.empty())
	{
		a = q.front();
		q.pop();
		if (a.x == ex&&a.y == ey&&a.z == ez)
			return a.step;
		next.step = a.step + 1;
		for (int i = 0; i < 6; i++)
		{
			next.x = a.x + fx[i][0];
			next.y = a.y + fx[i][1];
			next.z = a.z + fx[i][2];
			if (check(next))
			{
				vis[next.x][next.y][next.z] = 1;
				next.step = a.step + 1;
				q.push(next);
			}

		}
	}
	return 0;
}
int main()
{
	while (scanf("%d%d%d", &k, &n, &m) == 3)
	{
		if (k + n + m == 0)break;
		for (int i = 0; i < k; i++)
		{
			for (int j = 0; j < n; j++)
			{
				scanf("%s", ma[i][j]);
				for (int r = 0; r < m; r++)
				{
					if (ma[i][j][r] == 'S')
					{
						sx = i, sy = j, sz = r;
					}
					else if (ma[i][j][r] == 'E')
					{
						ex = i, ey = j, ez = r;
					}
				}
			}
		}
		memset(vis, 0, sizeof(vis));
		int ans = bfs();
		if (ans)printf("Escaped in %d minute(s).\n", ans);
		else puts("Trapped!");

	}return 0;
}