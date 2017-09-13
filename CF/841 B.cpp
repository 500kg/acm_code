#include<bits/stdc++.h>
using namespace std;
int a[200];
int main()
{
	int n;
	cin >> n;
	while (n--)
	{
		int a;
		scanf("%d", &a);
		if (a & 1)
		{
			puts("First");
			return 0;
		}
	}
	puts("Second");
}