#include<bits/stdc++.h>
using namespace std;
long long ans[25];
void init()
{
	ans[1] = 0;
	ans[2] = 1;
	ans[3] = 2;
	for (int i = 4; i <= 23; i++)
		ans[i] = (i - 1)*(ans[i - 1] + ans[i - 2]);
}

int main()
{
	init();
	int n;
	while (scanf("%d", &n) == 1)
		printf("%lld\n", ans[n]);
	return 0;
}