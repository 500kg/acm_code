#include<bits/stdc++.h>
using namespace std;
int len(long long a)
{
	int cnt = 0;
	while (a)
	{
		cnt++;
		a /= 10;
	}
	return cnt;
}
int main()
{
	long long w, m, k;
	cin >> w >> m >> k;
	w /= k;
	long long tmp = 1;
	while (m > tmp)
	{
		tmp *= 10;
	}
	tmp--;
	long long ans = 0;
	while (1)
	{
		if (len(tmp)*(tmp - m) > w)
		{
			ans += (w / len(tmp));
			break;
		}
		else
		{
			w -= len(tmp)*(tmp - m+1);
			ans += (tmp - m+1);
			m = tmp + 1;
			tmp = tmp * 10 + 9;
		}
	}
	cout << ans << endl;
}