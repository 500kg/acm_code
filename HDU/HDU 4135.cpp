#include<bits/stdc++.h>
using namespace std;
int kase = 0;
long long a[1005];
long long len;
void su(long long n)
{
	long long i;
	int num = 0;
	for (i = 2; i*i <= n; i++)
	{
		if (n%i == 0)
		{
			a[num++] = i;
			while (n%i == 0)
				n = n / i;
		}
	}
	if (n>1)
		a[num++] = n;
	len = num;
}
long long dfs(int pos, long long n)
{
	long long ans = 0;
	for (int i = pos; i < len; i++)
		ans += n / a[i] - dfs(i + 1, n / a[i]);
	return ans;
}

int main()
{
	int T; cin >> T; while (T--)
	{
		long long a, b, n;
		cin >> a >> b >> n;
		su(n);
		long long ans = (b - dfs(0, b) - (a - 1 - dfs(0, a - 1)));
		printf("Case #%d: %lld\n", ++kase, ans);
	}
}