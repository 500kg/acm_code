#include<bits/stdc++.h>
using namespace std;
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
int n, m;
int f[110][110];
int dp[110];

int main()
{
	while (~scanf("%d%d", &n, &m))
	{
		if (n == 0 && m == 0)break;
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++)
				scanf("%d", &f[i][j]);
		memset(dp, 0, sizeof(dp));
		for (int i = 1; i <= n; i++)
			for (int j = m; j >= 1; j--)
				for (int k = 1; k <= j; k++)
					dp[j] = max(dp[j], dp[j - k] + f[i][k]);
		cout << dp[m] << endl;
	}
}
