#include<bits/stdc++.h>
using namespace std;

int main()
{
	long long l, r, a, b, k, i;
	cin >> l >> r >> a >> b >> k;
	for ( i = a; i <= b; i++)
	{
		if ((i*k >= l) && (i*k <= r))
		{
			puts("YES");
			return 0;
		}
	}
	puts("NO");
	return 0;
}