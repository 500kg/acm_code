#include<bits/stdc++.h>
using namespace std;

int main()
{
	int T;
	cin >> T; getchar(); while (T--)
	{
		char c[1000006];
		scanf("%s", c);
		int sum = 0;
		for (int i = 0; c[i] != '\0'; i++)
			sum += (c[i] - '0');
		printf("%d\n", sum % 9);
	}

}