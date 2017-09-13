#include<cstring>
#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cmath>
using namespace std;
const int maxn = 200000 + 50;
int ffmax[maxn][20], ffmin[maxn][20];
int n, q;
void init()
{
	int i, j, lg = floor(log10(double(n)) / log10(double(2)));
	for (j = 1; j <= lg; ++j) {
		for (i = 1; i <= n + 1 - (1 << j); ++i) { 
			ffmax[i][j] = max(ffmax[i][j - 1], ffmax[i + (1 << (j - 1))][j - 1]);
			ffmin[i][j] = min(ffmin[i][j - 1], ffmin[i + (1 << (j - 1))][j - 1]);
		}
	}
}
int main()
{
	while (scanf("%d%d", &n, &q) == 2)
	{
		int h;
		memset(ffmax, 0, sizeof(ffmax));
		memset(ffmin, 0, sizeof(ffmin));
		for (int i = 1; i <= n; ++i) {
			scanf("%d", &h);
			ffmax[i][0] = ffmin[i][0] = h;
		}
		init();
		while (q--)
		{
			int a, b;
			scanf("%d%d", &a, &b);
			if (a > b)swap(a, b);
			if (a > b) swap(a, b);
			int lg = floor(log10(double(b - a + 1)) / log10(double(2)));
			printf("%d\n", max(ffmax[a][lg], ffmax[b - (1 << lg) + 1][lg]) -
				min(ffmin[a][lg], ffmin[b - (1 << lg) + 1][lg]));
		}
	}