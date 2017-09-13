#include<algorithm>
#include<cstring>
#include<iostream>
#include<cstdio>
using namespace std;
int Max[255][255][8][8], Min[255][255][8][8];
int mm[505];
int N, B, K;
void init()
{
	mm[0] = -1;
	for (int i = 1; i <= 500; i++)
		mm[i] = ((i&(i - 1)) == 0) ? mm[i - 1] + 1 : mm[i - 1];
	for (int i = 0; i <= mm[N]; i++)
		for (int j = 0; j <= mm[N]; j++)
			if (i + j)
				for (int p = 1; p + (1 << i) - 1 <= N; p++)
					for (int q = 1; q + (1 << j) - 1 <= N; q++)
					{
						if (i)
						{
							Max[p][q][i][j] = max(Max[p][q][i - 1][j], Max[p + (1 << (i - 1))][q][i - 1][j]);
							Min[p][q][i][j] = min(Min[p][q][i - 1][j], Min[p + (1 << (i - 1))][q][i - 1][j]);
						}
						else
						{
							Max[p][q][i][j] = max(Max[p][q][i][j - 1], Max[p][q + (1 << (j - 1))][i][j - 1]);
							Min[p][q][i][j] = min(Min[p][q][i][j - 1], Min[p][q + (1 << (j - 1))][i][j - 1]);
						}
					}

}
int findmax(int x1, int y1, int x2, int y2)
{
	int k1 = mm[x2 - x1 + 1];
	int k2 = mm[y2 - y1 + 1];
	x2 = x2 - (1 << k1) + 1;
	y2 = y2 - (1 << k2) + 1;
	return max(max(Max[x1][y1][k1][k2], Max[x1][y2][k1][k2]), max(Max[x2][y1][k1][k2], Max[x2][y2][k1][k2]));
}
int findmin(int x1, int y1, int x2, int y2)
{
	int k1 = mm[x2 - x1 + 1];
	int k2 = mm[y2 - y1 + 1];
	x2 = x2 - (1 << k1) + 1;
	y2 = y2 - (1 << k2) + 1;
	return min(min(Min[x1][y1][k1][k2], Min[x1][y2][k1][k2]), min(Min[x2][y1][k1][k2], Min[x2][y2][k1][k2]));
}
int solve(int x, int y)
{
	return findmax(x, y, x + B - 1, y + B - 1) - findmin(x, y, x + B - 1, y + B - 1);
}
int main()
{
	
	while (scanf("%d%d%d", &N, &B, &K) == 3)
	{
		for (int i = 1; i <= N; i++)
			for (int j = 1; j <= N; j++)
			{
				scanf("%d", &Max[i][j][0][0]);
				Min[i][j][0][0] = Max[i][j][0][0];
			}
	
	//	cout << "aaa" << endl;
		init();
	//	cout << "aaa" << endl;
		while (K--)
		{
			int x, y;
			scanf("%d%d", &x, &y);
			printf("%d\n", solve(x, y));
		}
	}
}