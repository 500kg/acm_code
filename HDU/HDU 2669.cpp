#include<bits/stdc++.h>
using namespace std;
long long ExGCD(long long a, long long b, long long& x, long long& y)
{
	if (b == 0)
	{
		x = 1, y = 0;
		return a;
	}
	long long d = ExGCD(b, a%b, x, y);
	long long temp = x;
	x = y;
	y = temp - a / b*y;
	return d;
}
int main()
{
	long long a, b;
	while (scanf("%lld%lld", &a, &b) == 2)
	{
		long long x, y;
		long long t = ExGCD(a, b, x, y);
		if (t != 1)puts("sorry");
		else {
			while (x < 0)
			{
				x += b;
				y -= a;
			}
			printf("%lld %lld\n", x, y);
		}

	}
}