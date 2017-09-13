#include<bits/stdc++.h>
using namespace std;
int num,len;
int a[12], vis[12];
void ini()
{
	int n = 1; int i;
	for( i= 1; n <= 1000000; i++)
	{
		n *= i;
		a[i] = n;
	}
	 len = i-1;
}
void solve()
{
	memset(vis, 0, sizeof(vis));
	int flag = 0;
	/*for (int i = 1; i <= len; i++)
		printf("%d ", a[i]);*/
	while (num > 0)
	{
		if (flag)break;
		for(int i=1;i<=len;i++)
			if (a[i] <= num&&a[i + 1] > num)
				if(vis[i]==0)
			{
				num -= a[i]; vis[i] = 1;
				}
				else { flag = 1; break; }
	}
	if (flag)puts("No");
	else puts("Yes");
}

int main()
{
	int T; ini();
	cin >> T;
	while (T--)
	{
		cin >> num;
		solve();

	}
}