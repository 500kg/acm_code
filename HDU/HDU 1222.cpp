#include<bits/stdc++.h>
using namespace std;
long long Gcd(long long a,long long b)
{
	if (b == 0)
		return a;
	return Gcd(b, a % b);
}
int main()
{
	int T;
	cin >> T; while (T--)
	{
		long long m, n;
		scanf("%lld%lld", &m, &n);
		if (Gcd(m, n) == 1)puts("NO");
		else puts("YES");
	}
}