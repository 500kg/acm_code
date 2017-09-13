#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<cstring>
#include<queue>
using namespace std;
const int N = 200010;
int vis[N + 100];
int n, en;
/*
2017.8.23 
AC 47ms 1780kb G++
*/
struct node
{
	int x, step;
};
bool ok(int x)
{
	if (x >= 0 && x <= N && !vis[x])
		return 1;
	return 0;
}
int bfs(int x)
{
	int i;
	queue<node>q;
	node a, next;
	a.x = x;
	a.step = 0;
	q.push(a);
	vis[x] = 1;
	while (!q.empty())
	{
		a = q.front();
		q.pop();
		if (a.x == en)
			return a.step;
		next.step = a.step + 1;
		if (ok(a.x + 1))
		{
			next.x = a.x + 1;
			vis[next.x] = 1;
			q.push(next);
		}
		if (ok(a.x - 1))
		{
			next.x = a.x - 1;
			vis[next.x] = 1;
			q.push(next);
		}
		if (ok(a.x * 2))
		{
			next.x = a.x * 2;
			vis[next.x] = 1;
			q.push(next);
		}

	}
	return 10000000;
}
int main()
{
	while (scanf("%d%d", &n, &en) == 2)
	{
		memset(vis, 0, sizeof(vis));
		if (n > en)
		{
			printf("%d\n", n - en);
			continue;
		}
		cout << bfs(n) << endl;
	}
	return 0;
}