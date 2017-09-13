#include<stdio.h>
#include<iostream>
#include<cstring>
using namespace std;

const int MAXN = 1000;
int uN, vN;
int g[MAXN][MAXN];
int linker[MAXN];
bool used[MAXN];
bool dfs(int u)
{
	int v;
	for (v = 1; v<=vN; v++)
		if (g[u][v] && !used[v])
		{
			used[v] = true;
			if (linker[v] == -1 || dfs(linker[v]))
			{
				linker[v] = u;
				return true;
			}
		}
	return false;
}
int hungary()
{
	int res = 0;
	int u;
	memset(linker, -1, sizeof(linker));
	for (u = 1; u<=uN; u++)
	{
		memset(used, 0, sizeof(used));
		if (dfs(u))  res++;
	}
	return res;
}
int main()
{
	int n, m;
	while (scanf("%d%d", &n, &m) == 2)
	{
		uN = vN = n;
		memset(g, 0, sizeof(g));
		while (m--)
		{
			int x, y;
			scanf("%d%d", &x, &y);
			g[x][y] = 1;
		}
		cout << hungary() << endl;
	}
}