#include<bits/stdc++.h>
using namespace std;

int main()
{
	int a[1004];
	int T; cin >> T; while (T--)
	{
		memset(a, 0, sizeof(a));
		int n;
		cin >> n;
		int u, v;
		for (int i = 1; i <= n; i++)
		{
			cin >> u >> v;
			u = (u + 1) / 2, v = (v + 1) / 2;
			a[min(u, v)]++, a[max(u, v) + 1]--;
		}
		int ans = 0, t = 0;
		for (int i = 1; i <= 205; i++)
		{
			t += a[i];
			ans = max(ans, t);
		}
		ans *= 10;
		cout << ans << endl;
	}
}