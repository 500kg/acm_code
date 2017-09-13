#include<bits/stdc++.h>
using namespace std;
int c[50010], n;
int lowerbit(int x)
{
	return x&(-x);
}
void update(int x, int num)
{
	while (x <= n)
	{
		c[x] += num;
		x += lowerbit(x);
	}
}
int getsum(int x)
{
	int sum = 0;
	while (x > 0)
	{
		sum += c[x];
		x -= lowerbit(x);
	}
	return sum;
}
int main()
{
	int T;
	cin >> T;
	int kase = 0;
	while (T--)
	{
		memset(c, 0, sizeof(c));
		printf("Case %d:\n", ++kase);
		cin >> n;
		for (int i = 1; i <= n; i++)
		{
			int x;
			scanf("%d", &x);
			update(i, x);
		}
		char s[10];
		int a, b;
		while (scanf("%s", s) == 1 && strcmp(s, "End"))
		{
			scanf("%d%d", &a, &b);
			if (s[0] == 'Q')
				printf("%d\n", getsum(b) - getsum(a - 1));
			else if (s[0] == 'A')
				update(a, b);
			else
				update(a, -b);
		}
	}
}