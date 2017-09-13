#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;
int a[5][5];
int mon;
void fan(int x, int y)
{
	a[x][y] = 1 - a[x][y];
	a[x + 1][y] = 1 - a[x + 1][y];
	a[x][y + 1] = 1 - a[x][y + 1];
	if (x > 0)a[x - 1][y] = 1 - a[x - 1][y];
	if (y > 0)a[x][y - 1] = 1 - a[x][y - 1];
}
int iif()
{
	int x = a[0][0];
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			if (a[i][j] != x)return 0;
	return 1;
}
void dfs(int dep,int cnt)
{
	//printf("%d %d\n", x, y);
	if (dep==16)
	{
		if (iif())
		{
			mon = min(mon, cnt);
		//	cout << mon << endl;
		}
	}
	else
	{
		int x = dep % 4;
		int y = dep / 4;
		
		dfs(dep + 1, cnt);
		fan(x, y);
		dfs(dep + 1, cnt + 1);
		fan(x, y);
	}
}
int main()
{
	char s;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			cin >> s;
			if (s == 'b')a[i][j] = 1;
			else a[i][j] = 0;
		}
		getchar();
	}
	mon = 100000;
	dfs(0, 0);
	if (mon == 100000)puts("Impossible");
	else printf("%d\n", mon);
}