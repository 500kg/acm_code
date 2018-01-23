#include<bits/stdc++.h>
using namespace std;
int prime(int x)
{
	if (x == 1)
		return 0;
	for (int i = 2; i*i <= x; i++)
		if (x%i == 0)
			return 0;
	return 1;
}
int main()
{
	int l, r;
	cin >> l >> r;
	int flag = 0;
	for (int i = l; i <= r; i++)
	{
		int tmp = i;
		int tmp2 = 0;
		while (tmp)
		{
			tmp2 = tmp2 * 10 + tmp % 10;
			tmp /= 10;
		}
		if (prime(i) && prime(tmp2))
		{
			if (flag)
				cout << ',';
			cout << i;
			flag = 1;
		}
	}
	if (!flag)
		puts("No");
	else
		puts("");
}