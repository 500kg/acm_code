#include<bits/stdc++.h>
using namespace std;

int main()
{
	long long l, r;
	while (scanf("%lld%lld", &l, &r) == 2)
	{
		if (l == 0)l = 1;
		if (r <= 1)cout << 0 << endl;
		else if (r <= 2)cout << 1 << endl;
		else if (r - l <= 3)cout << 2 << endl;
		else cout << (r - l) / 2 + 1 << endl;
	}
}