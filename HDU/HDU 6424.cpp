#include<bits/stdc++.h>
using namespace std;

typedef pair<long long, long long >PLL;
typedef pair<PLL, PLL>PIIII;
typedef long long ll;
ll a[5], b[5];
const ll INF = 0x3f3f3f3f3f3f;
PLL gao(ll a, ll b)
{
	if (a > b)swap(a, b);
	return make_pair(a, b);
}
int main()
{
	//cout << INF << endl;
	int T; cin >> T; while (T--)
	{
		int n, m;
		cin >> n >> m;
		for (int i = 0; i < 3; i++)a[i] = b[i] = INF;
		for (int i = 0; i < n; i++)scanf("%lld", &a[i]);
		for (int j = 0; j < m; j++)scanf("%lld", &b[j]);
		PLL a1 = gao(a[0] + 2, INF);
		PLL a2 = gao(a[1] + 1, a[2]);
		PLL b1 = gao(b[0] + 2, INF);
		PLL b2 = gao(b[1] + 1, b[2]);
	//	gao(a1), gao(a2), gao(b1), gao(b2);
		if (a1 > a2)swap(a1, a2);
		if (b1 > b2)swap(b1, b2);
		PIIII A= make_pair(a1, a2);
		PIIII B = make_pair(b1, b2);
		int ans = 0;
		if (A < B)ans = 1;
		else if (A > B)ans = -1;
		printf("%d\n", ans);
	}
}