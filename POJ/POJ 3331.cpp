#include<iostream>
#define MAX 100000
using namespace std;
int main()
{
	int n, a[MAX];
	int i, j, k, count, temp;
	int T;
	cin >> T;
	while(T--)
	{
		int kase;
		scanf("%d%d", &n, &kase);
		a[0] = 1;
		count = 1;
		for (i = 1; i <= n; i++)
		{
			k = 0;
			for (j = 0; j<count; j++)
			{
				temp = a[j] * i + k;
				a[j] = temp % 10;
				k = temp / 10;
			}
			while (k)//记录进位    
			{
				a[count++] = k % 10;
				k /= 10;
			}
		}
		long long ans = 0;
		for (j = MAX - 1; j >= 0; j--)
			if (a[j])
				break;//忽略前导0
		for (i = count - 1; i >= 0; i--)
		{
			//cout << a[i];
			if (a[i] == kase)
				ans++;
		}
		printf("%lld \n", ans);
	}
	return 0;
}