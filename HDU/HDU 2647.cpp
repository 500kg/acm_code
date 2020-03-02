#include<bits/stdc++.h>
using namespace std;
int r[20005];
int main()
{
	int n, m;
	while (~scanf("%d%d", &n, &m))
	{
		vector<int >br[20005];
		memset(r, 0, sizeof(r));
		for (int i = 0; i < m; i++)
		{
			int u, v;
			scanf("%d%d", &u, &v);
			br[v].push_back(u);
			r[u]++;
		}
		int rn = 888;
		int ans = 0;
		int tot, temp[20005];
		int flag = 1;
		for (int i = 0; i < n; i+=tot)
		{
			tot = 0;
			for (int j = 1; j <= n; j++)
			{
				if (r[j] == 0)
				{
					r[j]=-1;
					temp[tot++] = j;
				}
			}
			if (tot == 0)
			{
				flag = 0;
				break;
			}
			ans += tot*rn; rn++;
			for (int j = 0; j < tot; j++)
			{
				for (int k = 0; k < br[temp[j]].size(); k++)
					r[br[temp[j]][k]]--;
			}
		}
		if (flag)
			cout << ans << endl;
		else
			puts("-1");
	}
	return 0;
}