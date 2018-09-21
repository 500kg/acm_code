#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[1000];
int s[1000];
int ans[1000];
int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)scanf("%d", &a[i]), s[a[i]]++;
	int cnt = 0;
	int rua = 0;
	for (int i = 1; i <= 100; i++)
	{
		if (s[i] == 1)
			cnt++;
		else if (s[i] > 2)
			rua++;
	}
	int cnt1 = cnt / 2, cnt2 = cnt - cnt1;
	int c1 = 0, c2 = 0;
	if (rua || cnt % 2 == 0)
	{
		for (int i = 1; i <= n; i++)
		{
			if (s[a[i]] == 1)
			{
				if (c1 < cnt1)ans[i] = 1, c1++;
				else ans[i] = 2, c2++;
			}
			else if (s[a[i]] == 2)
			{
				ans[i] = 1;
			}
			else
			{
				if (cnt2 > cnt1)
					ans[i] = 1, cnt2--;
				else ans[i] = 2;
			}
		}
	}
	else
	{
		cout << "NO" << endl;
		return 0;
	}
	cout << "YES" << endl;
	for (int i = 1; i <= n; i++)
	{
		printf("%c", ans[i] == 1 ? 'A' : 'B');
	}printf("\n");
}