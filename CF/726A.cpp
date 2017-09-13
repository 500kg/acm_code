#include<bits/stdc++.h>
using namespace std;
long long Gcd(long long a, long long b)
{
	if (b == 0)
		return a;
	return Gcd(b, a % b);
}
long long LCM(long long a, long long b)
{
	long long ans = a*b / Gcd(a, b);
	return ans;
}
int main()
{
	int T; cin >> T; while (T--)
	{
		long long n; cin >> n;
		long long ans,a;
		cin >> ans;
		for (int i = 1; i < n; i++)
		{
			cin >> a;
			ans = LCM(ans, a);
		}

		cout << ans << endl;
	}
}