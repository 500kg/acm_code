#include<bits/stdc++.h>
using namespace std;
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

