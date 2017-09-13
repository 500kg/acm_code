#include<bits/stdc++.h>
using namespace std;
int n, m, k, s;
int v[105], c[105];
int dp[105][105]; //【消耗忍耐度】【杀怪数】
/*

         七律·咏蔡盛梁
            魔表群友
沪上有个蔡盛梁，脸长腿长**长。
魔表爸爸sub4  ，空中飞人正面肛。
天天指点刘艾文，能把WK虐出翔。
十月北京亚锦赛，亚洲冠军不用讲。
麻将桥牌15p，多才多艺痴情郎。
最爱魔友孙啦啦，撸管射老师脸上。
全校第一无卵用，实事求是装逼强。
世界魔友齐膜拜，毕竟上海全能王。

*/
int main()
{
	while (scanf("%d%d%d%d", &n, &m, &k, &s) == 4)
	{
		memset(dp, 0, sizeof(dp));
		for (int i = 1; i <= k; i++)
			scanf("%d%d", &v[i], &c[i]);
		for (int i = 1; i <= k; i++)
			for (int j = c[i]; j <= m; j++)
				for (int t = 1; t <= s; t++)
					if (dp[j][t]<dp[j - c[i]][t - 1] + v[i])
						dp[j][t] = dp[j - c[i]][t - 1] + v[i];
		if (dp[m][s] < n)
		{
			puts("-1");
			continue;
		}
		else
		{
			for (int i = 0; i <= m; i++)
				if (dp[i][s] >= n)
				{
					cout << m - i << endl;
					break;
				}
		}
	}
}

