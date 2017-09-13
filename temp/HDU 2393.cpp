#include<bits/stdc++.h>
using namespace std;
int main()
{
	int T;
	int kase = 0;
	cin >> T;
	while (T--)
	{
		long long a[3];
		for (int i = 0; i < 3; i++)
			scanf("%lld", &a[i]);
		sort(a, a + 3);
		printf("Scenario #%d:\n", ++kase);
		if ((a[0] * a[0] + a[1] * a[1]) == (a[2] * a[2]))
			puts("yes");
		else 
			puts("no");
		puts("");
	}
}