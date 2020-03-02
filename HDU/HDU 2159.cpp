#include<bits/stdc++.h>
using namespace std;
int n, m, k, s;
int v[105], c[105];
int dp[105][105]; //���������Ͷȡ���ɱ������
/*

         ���ɡ�ӽ��ʢ��
            ħ��Ⱥ��
�����и���ʢ���������ȳ�**����
ħ��ְ�sub4  �����з�������ء�
����ָ�������ģ��ܰ�WKŰ���衣
ʮ�±����ǽ��������޹ھ����ý���
�齫����15p����Ŷ��ճ����ɡ�
�ħ����������ߣ������ʦ���ϡ�
ȫУ��һ�����ã�ʵ������װ��ǿ��
����ħ����Ĥ�ݣ��Ͼ��Ϻ�ȫ������

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

