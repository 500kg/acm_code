
#include<bits/stdc++.h>
using namespace std;
int n, m;
int g[1005][13], c[1005], v[1005];
int main()
{

	while (scanf("%d%d", &n, &m) == 2)
	{
		memset(g, 0, sizeof(g));
		memset(c, 0, sizeof(c));
		memset(v, 0, sizeof(v));
		while (n--)
		{
			int b, f;
			scanf("%d%d", &b, &f);
			g[b][f]++;
		}
	}
}