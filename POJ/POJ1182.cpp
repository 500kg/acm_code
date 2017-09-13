#include<iostream>
#include<stdio.h>
using namespace std;
const int maxN = 50005;
int f[maxN * 3 + 10];
void ini()
{
	for (int i = 0; i < maxN * 3; i++)
		f[i] = i;
}
int find(int x)
{
	if (x != f[x])f[x] = find(f[x]);
	return f[x];
}
void uni(int x, int y)
{
	x = find(x);
	y = find(y);
	if (x != y)
		f[x] = y;
}
bool same(int x, int y)
{
	return find(x) == find(y);
}
int main()
{
	int n, k;
	scanf("%d%d", &n, &k);int cnt = 0;
	ini();
	while (k--)
	{
		int t, a, b;
		
		scanf("%d%d%d", &t, &a, &b);
		if (a > n || b > n)
		{
			cnt++;
			continue;
		}
		if (t == 1)
		{
			if (same(a, b + n) || same(a, b + 2*n))
				cnt++;
			else
			{
				uni(a, b); 
				uni(a + n, b + n);
				uni(a + 2 * n, b + 2 * n);
			}
		}
		else
		{
			if (same(a, b) || same(a, b + 2 * n))
				cnt++;
			else
			{
				uni(a, b + n);
				uni(a + n, b + 2 * n);
				uni(a + 2 * n, b);
			}
		}
		
	}cout << cnt << endl;
}