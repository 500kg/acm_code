#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n, m, t;
	char c;
	cin >> n >> m >> c >> t;
	if (t)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
				cout << c;
			cout << endl;
		}
	}
	else
	{
		for (int i = 0; i < m; i++)
			cout << c;
		cout << endl;
		for (int i = 1; i < n - 1; i++)
		{
			cout << c;
			for (int j = 1; j < m - 1; j++)
				cout << ' ';
			cout << c << endl;
		}
		for (int i = 0; i < m; i++)
			cout << c;
		cout << endl;
	}
}