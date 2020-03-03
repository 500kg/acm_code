#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
const int maxn = 1e5 + 50;
int a[maxn];
int main()
{
	int T; cin >> T; while (T--)
	{
		int n; scanf("%d", &n);
		for (int i = 0; i < n; i++)
			scanf("%d", &a[i]);
		int ans = 0;
		ans = max(a[n - 1] - a[1] - n + 2, a[n - 2] - a[0] - n + 2);
		printf("%d\n", ans);
	}

}