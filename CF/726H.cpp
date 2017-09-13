#include<bits/stdc++.h>
using namespace std;
int a[15], b[15]; LL n;
typedef long long LL ;
LL Gcd(LL a, LL b)
{
	if (b == 0)
		return a;
	return Gcd(b, a % b);
}
LL ExGCD(LL a, LL b, LL& x, LL& y)
{
	if (b == 0)
	{
		x = 1, y = 0;
		return a;
	}
	LL d = ExGCD(b, a%b, x, y);
	LL temp = x;
	x = y;
	y = temp - a / b*y;
	return d;
}
void solve()
{

}
int main()
{
	LL T; cin >> T; while (T--)
	{
		 cin >> n;
		for (int i = 1; i <= n; i++)cin >> a[i];
		for (int j = 1; j <= n; j++)cin >> b[j];
		solve();
	}
}