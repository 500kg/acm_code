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
int v[1005], c[1005];
int dp[1005];
int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		memset(dp, 0, sizeof(dp));
		int n, V;
		scanf("%d%d", &n, &V);
		for (int i = 1; i <= n; i++)
			scanf("%d", v + i);
		for (int i = 1; i <= n; i++)
			scanf("%d", c + i);
		for (int i = 1; i <= n; i++)
			for (int j = V; j >= c[i]; j--)
				if (dp[j]<dp[j - c[i]] + v[i])
					dp[j] = dp[j - c[i]] + v[i];
		cout << dp[V] << endl;
	}
	return 0;

}

