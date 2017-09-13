#include<bits/stdc++.h>
using namespace std;
int f[2000];
void init(int n)
{
	for (int i = 0; i <= n; i++)
		f[i] = i;
}
int find(int x)
{
	if (x == f[x])return x;
	return f[x] = find(f[x]);
}
void uni(int x, int y)
{
	x = find(x);
	y = find(y);
	if (x != y)
		f[x] = y;
}
int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		int n, m;
		scanf("%d%d", &n, &m);
		init(n);
		int a, b;
		for (int i = 0; i < m; i++)
		{
			scanf("%d%d", &a, &b);
			uni(a, b);
		}
		set<int>rua;
		for (int i = 1; i <= n; i++)
		{
			rua.insert(find(f[i]));
		}
		printf("%d\n", rua.size());
	}
}