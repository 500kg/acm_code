#include<bits/stdc++.h>
using namespace std;
long long cell[25][25];
bool vis[25][25];
int fx[4] = { 0,1,0,-1 };
int fy[4] = { 1,0,-1,0 };
int N, M, Q;
bool ok(int x1,int y1)
{
	if (x1 >= M || x1 < 0)return 0;
	if (y1 >= N || y1 < 0)return 0;
	return 1;
}
void dfs(int x,int y)
{
	vis[x][y] = 1;
	for (int i = 0; i < 4; i++)
	{
		int tx = x + fx[i];
		int ty = y + fy[i];
		if (ok(tx,ty)&&!vis[tx][ty] && cell[tx][ty]==cell[x][y])
			dfs(tx, ty);
	}
}
void mark(int x1, int y1, int x2, int y2,int cnt)
{
	long long num = 1 << cnt;
	for (int i = x1; i < x2; i++)
		for (int j = y1; j < y2; j++)
			cell[i][j] += num;
}
int main()
{
	
	while (scanf("%d%d", &N, &M) == 2 && N + M);
	{
		scanf("%d", &Q);
		memset(vis, 0, sizeof(vis));
		memset(cell, 0, sizeof(cell));
		int a, b, c, d;
		int t = 0;
		for (int i = 0; i < Q; i++)
		{
			scanf("%d%d%d%d", &a, &b, &c, &d);
			if (a > c)swap(a, c);
			if (b > d)swap(b, d);
			mark(a, b, c, d, t++);
		}
		int cnt = 0;
		for (int i = 0; i < M; i++)
		{
			for (int j = 0; j < N; j++)
			{
			//	printf("%lld", cell[i][j]);
					if (!vis[i][j])
					{
						dfs(i, j);
					/*	for (int i = 0; i < M; i++)
						{
							for (int j = 0; j < N; j++)
								printf("%d", vis[i][j]);
							puts("");
						}
						printf("%d\n", cnt);*/
						cnt++;
					}
			}
			//cout << endl;
		}
		printf("%d\n", cnt);
	}
}