#include<bits/stdc++.h>
using namespace std;

int main()
{
	int k;
	char c[100005];
	int s[100005];
	int a[15]; memset(a, 0, sizeof(a));
	
	cin >> k >> c;
	long long sum = 0;
	int cnt = 0;
	for (int i = 0; c[i] != '\0'; i++)
	{
		sum += (c[i] - '0');
		a[c[i] - '0']++;
	}
	/*for (int i = 0; i < 10; i++)
		printf("%d", a[i]);*/
	int i = 0;
	while (k > sum)
	{
		if (a[i] > (k - sum + 8 - i) / (9 - i))
		{
			cnt += (k - sum + 8 - i) / (9 - i);
			break;
		}
		else
		{
			cnt += a[i];
			sum += a[i] * (9 - i);
		}
		i++;
	}
	cout << cnt << endl;
}