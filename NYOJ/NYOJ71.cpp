#include<bits/stdc++.h>
using namespace std;
int w, n;
int a[305];
void test()
{
	for (int i = 1; i <= 6; i++)
		printf("%d ", a[i]);
	puts("");
}
void solve()
{
	int ans = 0;
	sort(a + 1, a + n + 1);
	while(n)
	{
	//	test();
		if (a[n] == -1) { n--; continue; }
		int now = w - a[n]; a[n] = -1; n--;
	//	cout << now << endl;
		for(int i=n;i>0;i--)
			if (a[i] <= now&&a[i]!=-1)
			{
				a[i] = -1; break;
			}
		ans++;
	}
	cout << ans << endl;
}
int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		cin >> w >> n;
		for (int i = 1; i <= n; i++)
			cin >> a[i];
		solve();

	}
}