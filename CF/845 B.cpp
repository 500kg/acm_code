#include<bits/stdc++.h>
using namespace std;
int a[300];
int main()
{
	char ch[100];
	scanf("%s", ch);
	int a[100];
	int b[10];
	int sum1 = 0, sum2 = 0;
	for (int i = 0; i < 6; i++)
	{
		a[i] = ch[i] - '0';
		if (i < 3)sum1 += a[i];
		else sum2 += a[i];
	}
	if (sum1 == sum2)
		printf("0\n");
	else if (sum1 < sum2)
	{
		int cha = sum2 - sum1;
		b[0] = 9 - a[0], b[1] = 9 - a[1], b[2] = 9 - a[2], b[3] = a[3], b[4] = a[4], b[5] = a[5];
		sort(b, b + 6);
		int cnt = 0;
		for (int i = 5; i >= 0; i--)
		{
			cha -= b[i];
			cnt++;
			if (cha <= 0)break;
		}
		printf("%d\n", cnt);
	}
	else
	{
		int cha = sum1 - sum2;
		b[0] = a[0], b[1] = a[1], b[2] = a[2], b[3] = 9 - a[3], b[4] = 9 - a[4], b[5] = 9 - a[5];
		sort(b, b + 6);
		int cnt = 0;
		for (int i = 5; i >= 0; i--)
		{
			cha -= b[i];
			cnt++;
			if (cha <= 0)break;
		}
		printf("%d\n", cnt);
	}
	
}