#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std;
int gcd(int a, int b) { return b == 0 ? a : gcd(b, a%b); }

int main()
{
	int n;
	while (cin >> n)
	{
		if (n == 0)
		{
			cout << 0 << endl;
			continue;
		}
		if (n == -1)break;
		long long ans = 0;
		for (int i = 1; i <= n; i++)
			ans += pow(3, gcd(i, n));
		//	cout << ans << endl;
		if (n % 2)
			ans += n * pow(3, n / 2 + 1);
		else
			ans += n * (pow(3, n / 2) / 2 + pow(3, n / 2 + 1) / 2);
		cout << ans / (2 * n) << endl;
	}

}
