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
