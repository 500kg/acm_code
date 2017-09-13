#include<bits/stdc++.h>
using namespace std;
int min_num[100005][20];
int max_num[100005][20];
int n, k;
void RMQ()
{
	for (int i = 1; i<20; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (j + (1 << i) - 1 <= n)
			{
				max_num[j][i] = max(max_num[j][i - 1], max_num[j + (1 << (i - 1))][i - 1]);
				min_num[j][i] = min(min_num[j][i - 1], min_num[j + (1 << (i - 1))][i - 1]);
			}
		}
	}

}
int main()
{
	scanf("%d %d", &n, &k);
	for (int i = 1; i <= n; i++)
	{
		int x;
		scanf("%d", &x);
		min_num[i][0] = max_num[i][0] = x;
	}
	RMQ();
	for (int i = 0; i<k; i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		int pos = (int)(log(b - a + 1.0) / log(2.0));
		int max1 = max(max_num[a][pos], max_num[b - (1 << pos) + 1][pos]);
		int min1 = min(min_num[a][pos], min_num[b - (1 << pos) + 1][pos]);
		printf("%d\n", max1 - min1);
	}
	return 0;
}