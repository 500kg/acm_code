#include<bits/stdc++.h>
using namespace std;
int a[100500];
int main()
{
	int n, t;
	cin >> n >> t;
	int x;
	int i;
	for ( i = 1; i <= n; i++)
	{
		cin >> x;
		t -= (86400 - x);
		if (t <= 0)break;
	}
	cout << i << endl;
}