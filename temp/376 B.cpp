#include<bits/stdc++.h>
using namespace std;
int t[10005];
int main()
{
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		t[a] += c;
		t[b] -= c;
	}
	int sum = 0;
	for (int i = 1; i <= n; i++)
		if (t[i] > 0)
			sum += t[i];
	cout << sum << endl;
}