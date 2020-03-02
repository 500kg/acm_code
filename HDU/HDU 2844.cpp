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

int v[105], c[105];
int dp[100005];
int n, m;
void ZeroOnePack(int c, int w)
{
	for (int v = m; v >= c; v--)
	{
		dp[v] = max(dp[v], dp[v - c] + w);
	}
}
void CompletePack(int c, int w)
{
	for (int v = c; v <=m; v++)
	{
		dp[v] = max(dp[v], dp[v - c] + w);
	}
}
void MultiplePack(int c, int w, int num)
{
	if (c * num >= m)
	{
		CompletePack(c, w);
	}
	else
	{
		int k = 1;
		while (k < num)
		{
			ZeroOnePack(k*c, k*w);
			num -= k;
			k <<= 1;
		}
		ZeroOnePack(num*c, num*w);
	}
}
int main()
{

	while (cin >> n >> m)
	{
		if (n == 0 && m == 0)
			break;
		for (int i = 0; i < n; i++)
			scanf("%d", &v[i]);
		for (int i = 0; i < n; i++)
			scanf("%d", &c[i]);
		memset(dp, 0, sizeof(dp));
		int id = 0;
		for (int i = 0; i < n; i++)
		{
			MultiplePack(v[i], v[i], c[i]);
		}
		int count = 0;
		for (int i = 1; i <= m; i++)
			if (dp[i] == i)
				count++;
		cout<<count<<endl;
	}
}
