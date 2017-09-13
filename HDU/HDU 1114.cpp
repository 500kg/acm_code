#include<bits/stdc++.h>
using namespace std;
/*

沪上有个蔡盛梁，脸长腿长**长。
魔表爸爸sub4  ，空中飞人正面肛。
天天指点刘艾文，能把WK虐出翔。
十月北京亚锦赛，亚洲冠军不用讲。
麻将桥牌15p，多才多艺痴情郎。
最爱魔友孙啦啦，撸管射老师脸上。
全校第一无卵用，实事求是装逼强。
世界魔友齐膜拜，毕竟上海全能王。

*/
int dp[10005];
const int INF = 0x3f3f3f3f;
int main()
{
	int T; cin >> T; while (T--)
	{
		int kkkk, tttt;
		scanf("%d%d", &kkkk, &tttt);
		int W = tttt - kkkk,n;
		for (int i = 1; i <= W; i++)
			dp[i] = INF;//初始化为无穷大
		dp[0] = 0;
		cin >> n;
		while (n--)
		{
			int p, w;
			scanf("%d%d", &p, &w);
			for (int i = w; i <=W; i++)
				if (dp[i]>dp[i - w] + p)
					dp[i] = dp[i - w] + p;
		}
		if (dp[W] == INF)
			puts("This is impossible.");
		else
			printf("The minimum amount of money in the piggy-bank is %d.\n", dp[W]);
	}
}
