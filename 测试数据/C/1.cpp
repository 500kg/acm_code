#include<bits/stdc++.h>
using namespace std;
int a[2000], b[2000];
int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < n; i++)
		cin >> b[i];
	long long ans = 0;
	for (int i = 0; i < n; i++)
		ans += a[i] * b[i];
	cout << ans << endl;
}