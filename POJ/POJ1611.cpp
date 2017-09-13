#include<iostream>
#include<stdio.h>

using namespace std;
int f[30005];
void ini()
{
	for (int i = 0; i <= 30003; i++)
		f[i] = i;
}
int find(int x)
{
	if (x != f[x])
		f[x] = find(f[x]);
	return f[x];
}
void uni(int x, int y)
{
	x = find(x);
	y = find(y);
	if (x != y)
		f[y] = x;
}
bool same(int x, int y)
{
	return find(x) == find(y);
}
int main()
{
	int n, m;
	
	while (scanf("%d%d", &m, &n) == 2&&n+m)
	{
		ini();
		for (int i = 0; i < n; i++)
		{

		//	printf("%d\n", i);
			int k,x,d;
			scanf("%d", &k);
			scanf("%d", &x);
			for (int t = 1; t < k; t++)
			{
				scanf("%d", &d);
				uni(x, d);
			}
		}
//		cout << 1 << endl;
		int ans = 0;
		for (int i = 0; i < m; i++)
			if (find(i) == find(0))
				ans++;
	//	printf("%d %d %d %d\n", find(0), find(1), find(2), find(99));
		cout << ans << endl;
	}
}