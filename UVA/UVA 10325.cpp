#include<bits/stdc++.h>
using namespace std;
int a[100];
int ans;
long long n, m;
long long Gcd(long long a, long long b) {
	return b == 0 ? a : Gcd(b, a%b);
}
void dfs(int now, long long num, int id)
{
	num = a[now] / Gcd(a[now], num)*num;
	if (id & 1)
		ans += n / num;
	else
		ans -= n / num;

	for (int i = now + 1; i < m; i++)
		dfs(i, num, id + 1);
}
int main()
{

	while (scanf("%lld%lld", &n, &m) == 2)
	{
		ans = 0;
		for (int i = 0; i < m; i++)
			scanf("%d", &a[i]);
		for (int i = 0; i < m; i++)
			dfs(i, 1, 1);
		cout << n-ans << endl;
	}
}

