#include<bits/stdc++.h>
using namespace std;
int a[100500];
int main()
{
	int n, t;
	int x;
	cin >> n >> t;
	long long ans = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> x;
		ans += x;
	}
	ans += (n - 1);
	if (t == ans||t == (ans + 2))
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
}