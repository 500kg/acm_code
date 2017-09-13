#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t[1000];
	int T; cin >> T; while (T--)
	{
		memset(t, 0, sizeof(t));
		int n;
		int ans = 0;
		cin >> n;
		int a, b;
		for (int i = 0; i < n; i++)
		{
			cin >> a >> b;
			a = (a + 1) / 2, b = (b + 1) / 2;
			for (int i = min(a, b); i <= max(a, b); i++)
				t[i]++, ans = max(ans, t[i]);
		}
		ans *= 10;
		cout << ans << endl;
		
	}
}
