#include<cstdio>
#include<iostream>
using namespace std;

int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		int n;
		scanf("%d", &n);
		printf("%d %d\n", n - (n&(-n)) + 1, n + (n&(-n)) - 1);
	}
}