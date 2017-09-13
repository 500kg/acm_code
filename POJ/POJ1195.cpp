#include<cstring>
#include<cstdio>
using namespace std;
const int maxn = 1100;
int c[maxn][maxn], n;
int lowbit(int x)
{
	return x&(-x);
}
void add(int x, int y, int v)
{
	for (int i = x; i <= n; i += lowbit(i))
		for (int j = y; j <= n; j += lowbit(j))
			c[i][j] += v;
}
int getsum(int x, int y)
{
	int sum = 0;
	for (int i = x; i > 0; i -= lowbit(i))
		for (int j = y; j > 0; j -= lowbit(j))
			sum += c[i][j];
	return sum;
}

int main()
{
	while (scanf("0%d", &n) == 1)
	{
		memset(c, 0, sizeof(c));
		int kase;
		while (scanf("%d", &kase) == 1 && kase != 3)
		{
			if (kase == 1)
			{
				int x, y, num;
				scanf("%d%d%d", &x, &y, &num);
				add(x + 1, y + 1, num);
			}
			else
			{
				int l, b, r, t;
				scanf("%d%d%d%d", &l, &b, &r, &t);
				printf("%d\n", getsum(r + 1, t + 1) - getsum(r + 1, b) - getsum(l, t + 1) + getsum(l, b));
			}
		}
	}
}