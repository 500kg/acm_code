#include<bits/stdc++.h>
using namespace std;
int a[100];
int main()
{
	int k;
	scanf("%d", &k);
	k *= 2;
	for (int i = 0; i < 4; i++)
	{
		getchar();
		char ch;
		for (int j = 0; j < 4; j++)
		{
			scanf("%c", &ch);
			if (ch != '.')
			{
				a[ch - '0']++;
			}
		}
	}
	for(int i=1;i<=10;i++)
		if (a[i] > k)
		{
			puts("NO");
			return 0;
		}
	puts("YES");
	return 0;
}