#include<stdio.h>
#include<string.h>
int c1[251][101], c2[251][101];//[系数][个数]
void init()
{
	int val[6] = { 0,1,5,10,25,50 };
	memset(c1, 0, sizeof(c1));
	memset(c2, 0, sizeof(c2));
	for (int i = 0; i <= 100; i++)
	{
		c1[i][i] = 1;
	}
	int n = 250;
	for (int i = 2; i <= 5; i++)
	{
		for (int j = 0; j <= n; j++)
			for (int k = 0; k + j <= n; k += val[i])
				for (int l = 0; l + k / val[i] <= 100; l++)
					c2[k + j][l + k / val[i]] += c1[j][l];

		for (int k = 0; k <= n; k++)
			for (int l = 0; l <= 100; l++)
			{
				c1[k][l] = c2[k][l];
				c2[k][l] = 0;
			}
	}
}
int main()
{
	init();
	int n;
	while (scanf("%d", &n) == 1)
	{
		long long sum = 0;
		for (int i = 0; i <= 100; i++)
			sum += c1[n][i];
		printf("%d\n", sum);
	}
	return 0;
}

