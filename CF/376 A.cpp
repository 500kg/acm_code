#include<bits/stdc++.h>
using namespace std;

int main()
{
	char ch[1000040];
	while (cin >> ch)
	{
		int mid;
		for (int i = 0; ch[i] != '\0'; i++)
			if (ch[i] == '^')
			{
				mid = i;
				break;
			}
		long long left = 0, right = 0;
		for (int i = 0; i < mid; i++)
		{
			if (ch[i] >= '0'&&ch[i] <= '9')
			{
				left += (mid - i)*(ch[i] - '0');
			}
		}
		for (int i = mid + 1; ch[i] != '\0'; i++)
		{
			if (ch[i] >= '0'&&ch[i] <= '9')
				right += (i - mid)*(ch[i] - '0');
		}
		if (left < right)
			puts("right");
		else if (left == right)
			puts("balance");
		else puts("left");
	}
}