#include<bits/stdc++.h>
using namespace std;
long long Gcd(long long a, long long b) {
	return b == 0 ? a : Gcd(b, a%b);
}
int kase = 0;
int main()
{
	int T;
	cin >> T; while (T--)
	{
		int n, a, b;
		cin >> n >> a >> b;
		int num = n / Gcd(a, b);
		if (num % 2 == 0)printf("Case #%d: Iaka\n", ++kase);
		else printf("Case #%d: Yuwgna\n", ++kase);
	}
}