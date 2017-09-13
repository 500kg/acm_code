#include<iostream>
#include<stdio.h>
#include<math.h>
#include<algorithm>
using namespace std;
int main()
{
	int a, b, c, d, e, f;
	while (scanf("%d%d%d%d%d%d", &a, &b, &c, &d, &e, &f) == 6)
	{
		if (a == 0 && b == 0 && c == 0 && d == 0 && e == 0 && f == 0)break;
		int ans = 0;

		ans = f + e + d + (c + 3) / 4;

		int b2 = 5 * d;
		if (c % 4 == 0)b2 += 0;
		else if (c % 4 == 1)b2 += 5;
		else if (c % 4 == 2)b2 += 3;
		else b2 += 1;

		if (b > b2)ans += (b-b2 + 8) / 9;
		a -= ans * 36 - f * 36 - e * 25 - d * 16 - c * 9 - b * 4;
		if (a > 0)ans += (a + 35) / 36;
		cout << ans << endl;

	}
	return 0;
}
