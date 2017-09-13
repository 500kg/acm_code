#include<bits/stdc++.h>
using namespace std;
int n;
int a[1005];
void solve()
{
	int ans = 0;
	sort(a + 1, a + 1 + n);
	while (n >= 4)
	{
		int t1 = a[1] + a[2] * 2 + a[n];
		int t2 = a[1] * 2 + a[n - 1] + a[n];
		ans += min(t1, t2); n -= 2;
	}
	if (n == 3)ans += (a[1] + a[2] + a[3]);
	else if (n == 2)ans += a[2];
	else ans += a[1];
	cout << ans << endl;

}
int main()
{
	int T;
	cin >> T; while (T--)
	{
		cin >> n;
		for (int i = 1; i <= n; i++)
			cin >> a[i];
		solve();
	}
}