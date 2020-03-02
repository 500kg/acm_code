#include<bits/stdc++.h>
using namespace std;

int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		long long a, b;
		scanf("%lld%lld", &a, &b);
		printf("%lld\n", a*b - a - b);
	}
}