#include<bits/stdc++.h>
using namespace std;
/*

�����и���ʢ���������ȳ�**����
ħ��ְ�sub4  �����з�������ء�
����ָ�������ģ��ܰ�WKŰ���衣
ʮ�±����ǽ��������޹ھ����ý���
�齫����15p����Ŷ��ճ����ɡ�
�ħ����������ߣ������ʦ���ϡ�
ȫУ��һ�����ã�ʵ������װ��ǿ��
����ħ����Ĥ�ݣ��Ͼ��Ϻ�ȫ������

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
			dp[i] = INF;//��ʼ��Ϊ�����
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
