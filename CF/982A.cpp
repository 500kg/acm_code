#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL MOD = 1e9 + 7;
int main()
{
	int n; cin >> n;
	string s; cin >> s;
	int len = s.length();
	int flag = 1;
	for (int i = 0; i < len - 1; i++)
	{
		if (s[i] == '1'&&s[i + 1] == '1')
			flag = 0;
	}
	for (int i = 0; i < len - 2; i++)
	{
		if (s[i] == '0'&&s[i + 1] == '0'&&s[i + 2] == '0')
			flag = 0;
	}
	if (s[0] == '0'&&s[1] == '0')flag = 0;
	if (s[len - 1] == '0'&&s[len - 2] == '0')flag = 0; 
	if (n == 1 && s[0] == '0')flag = 0;
	if (flag)cout << "YES" << endl;
	else cout << "NO" << endl;
}
