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
int a[1005];
int f[1006];
int main()
{
	int n, m;
	while (scanf("%d", &n) == 1)
	{
		memset(f, 0, sizeof(f));
		if (n == 0)return 0;
		for (int i = 0; i < n; i++)
			scanf("%d", &a[i]);
		scanf("%d", &m);
		sort(a, a + n);
		for (int i = 0; i < n - 1; i++)
			for (int j = m - 5; j >= a[i]; j--)
				f[j] = max(f[j], f[j - a[i]] + a[i]);
		if (m < 5)
			cout << m << endl;
		else
			cout << m - f[m - 5] - a[n - 1] << endl;
	}
}

