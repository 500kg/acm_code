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

