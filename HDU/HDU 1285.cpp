#include<bits/stdc++.h>
using namespace std;
const int maxN = 5500;
int r[maxN];
vector<int>br[maxN];
int ans[maxN];
int vis[maxN];
int main()
{
	int n, m;
	while (scanf("%d%d", &n, &m) == 2)
	{
		memset(vis, 0, sizeof(vis));
		for (int i = 0; i < maxN; i++)
			br[i].clear();
		for (int i = 0; i < m; i++)
		{
			int a, b;
			scanf("%d%d", &a, &b);
			r[b]++;
			br[a].push_back(b);
		}
		int k = 0;
		while (k != n)
		{
			for (int i = 1; i <= n; i++)
			{
				if(!vis[i])
				if (r[i] == 0) {
					ans[k++] = i;
					vis[i] = 1;
					for (int j = 0; j < br[i].size(); j++)
						r[br[i][j]]--;
					break;
				}

			}
		}
		printf("%d", ans[0]);
		for (int i = 1; i < k; i++)
			printf(" %d", ans[i]);
		puts("");
	}

}
