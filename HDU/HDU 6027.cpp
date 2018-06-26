#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL MOD = 1e9 + 7;
int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		int n, k;
		cin >> n >> k;
		LL ans = 0;
		for (int i = 1; i <= n; i++)
		{
			LL tmp = 1;
			for (int j = 1; j <= k; j++)
				tmp = tmp * i%MOD;
			ans += tmp;
            ans%=MOD;
		}
		cout << ans << endl;
	}
}