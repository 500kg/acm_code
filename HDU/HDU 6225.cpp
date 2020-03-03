#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
int main()
{
	int T; cin >> T; while (T--)
	{
		ll a, b, c, d; scanf("%llu%llu%llu%llu", &a, &b, &c, &d);
		if (a == 4611686018427387904 && b == 4611686018427387904 && c == 4611686018427387904 && d == 4611686018427387904)
		{
			printf("18446744073709551616\n"); continue;
		}
		printf("%llu\n", a + b + c + d);
	}

}