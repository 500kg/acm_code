#include<bits/stdc++.h>
using namespace std;

int main()
{
	double n;
	while (cin >> n)
	{
		if (n < 5)
			cout << 2.5 - n << endl;
		else if (n < 10)
			cout << 2 - 1.5*(n - 3)*(n - 3) << endl;
		else
			cout << n / 2 - 1.5 << endl;
	}
}