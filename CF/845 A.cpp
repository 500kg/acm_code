#include<bits/stdc++.h>
using namespace std;
int a[300];
int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < 2 * n; i++)
		scanf("%d", &a[i]);
	sort(a, a + 2 * n);
	if (a[n] == a[n - 1])
		puts("NO");
	else
		puts("YES");
}