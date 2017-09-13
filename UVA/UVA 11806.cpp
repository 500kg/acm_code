#include<bits/stdc++.h>
using namespace std;
const int MAXN = 505;
long long C[MAXN][MAXN];
const int MOD = 1000007;
void ini() {
	memset(C, 0, sizeof(C));
	C[0][0] = 1;
	for (int i = 0; i < MAXN; i++) {
		C[i][0] = C[i][i] = 1;
		for (int j = 1; j < i; j++)
			C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % MOD;
	}
}

int main()
{
	ini();
	int kase = 0;
	int T; cin >> T; while (T--)
	{
		int n, m, k;
		scanf("%d%d%d", &n, &m, &k);
		long long ans = 0;
		ans += C[m*n][k]; //全
		ans = (ans + MOD) % MOD;
		ans -= (2 * C[(m - 1)*n][k] + 2 * C[m*(n - 1)][k]);  //一边无人
		ans = (ans + MOD) % MOD;
		ans += (4 * C[(m - 1)*(n - 1)][k] + C[(m - 2)*(n)][k] + C[m*(n - 2)][k]);
		ans = (ans + MOD) % MOD;
		ans -= (2 * C[(m - 2)*(n - 1)][k] + 2 * C[(m - 1)*(n - 2)][k]);
		ans = (ans + MOD) % MOD;
		ans += ( C[(m - 2)*(n - 2)][k]);
		ans = (ans + MOD) % MOD;
		printf("Case %d: %lld\n", ++kase, ans);
	}
}
