#include<bits/stdc++.h>
using namespace std;
long long a[15];int N, M;int x, m ;
long long ans;
long long Gcd(long long a, long long b) {
	return b == 0 ? a : Gcd(b, a%b);
}
void dfs(int now, long long num, int id)
{
	num = a[now] / Gcd(a[now], num)*num;
	if (id & 1)
		ans += N / num;
	else
		ans -= N / num;
	
	for (int i = now + 1; i < m; i++)
		dfs(i, num, id + 1);
}
int main()
{
	while (scanf("%d%d", &N, &M) == 2)
	{
		m = 0;
		for (int i = 0; i < M; i++)
		{
			cin >> x;
			if (x != 0)a[m++] = x;
		}
		N--;
		ans = 0; 
		for (int i = 0; i < m; i++)
			dfs(i, a[i], 1);
		
		cout << ans << endl;
	}

}