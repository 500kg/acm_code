#include<stdio.h>  
#include<string.h>  
#include<algorithm>  
#include<iostream>
using namespace std;
const int maxn = 510;
const int INF = 0x3f3f3f3f;

int w[maxn][maxn];
int d[maxn];
int vis[maxn];
int n;
int ans;

void Prime()
{
	for (int i = 1; i <= n; i++) d[i] = INF;
	d[1] = 0;
	memset(vis, 0, sizeof(vis));
	for (int i = 1; i <= n; i++)
	{
		int x, m = INF;
		for (int y = 1; y <= n; y++) if (!vis[y] && d[y] <= m) m = d[x = y];
		vis[x] = 1; ans = max(ans, d[x]);
		for (int y = 1; y <= n; y++) if (!vis[y])
			d[y] = min(d[y], w[x][y]);
	}
}
int main()
{
	int T; cin >> T; while (T--) {
		scanf("%d", &n);
		{
			for (int i = 1; i <= n; i++)
				for (int j = 1; j <= n; j++)
					scanf("%d", &w[i][j]);

			ans = 0;
			Prime();
			printf("%d\n", ans);
		}
	}
	return 0;
}