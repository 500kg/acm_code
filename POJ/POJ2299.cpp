#include<cstring>
#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn = 32050;
int sum[maxn], num[maxn];
int lowbit(int x)
{
	return x&(-x);
}

void add(int x, int num)
{
	while (x <= maxn)
	{
		sum[x] += num;
		x += lowbit(x);
	}
}
int getsum(int x)
{
	int s = 0;
	while (x)
	{
		s += sum[x];
		x -= lowbit(x);
	}
	return s;
}
int main()
{
	int n;
	while (scanf("%d", &n) == 1)
	{
		memset(sum, 0, sizeof(sum));
		memset(num, 0, sizeof(num));
		for (int i = 1; i <= n; i++)
		{
			int x, y;
			scanf("%d%d", &x, &y);
			num[getsum(x + 1)]++;
			add(x + 1, 1);
		}
		for (int i = 0; i < n; i++)
			printf("%d\n", num[i]);
	}
}