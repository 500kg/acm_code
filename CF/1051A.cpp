#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 50;
typedef long long ll;
string s;
int main()
{
	int T; cin >> T; while (T--)
	{
		cin >> s;
		int a1 = 0, a2 = 0, a3 = 0;
		for (int i = 0; i < s.length(); i++)
		{
			if (s[i] >= '0'&&s[i] <= '9')a1 ++;
			else if (s[i] >= 'a'&&s[i] <= 'z')a2 ++;
			else if (s[i] >= 'A'&&s[i] <= 'Z')a3 ++;
		}
		if (a1&&a2&&a3)
		{
			cout << s << endl;
			continue;
		}
		if ((a1&&a2)||(a2&&a3)||(a1&&a3))
		{
			if (!a1)
			{
				for (int i = 0; i < s.length(); i++)
				{
					if (s[i] >= 'a'&&s[i] <= 'z'&&a2 > 1)
					{
						s[i] = '1'; break;
					}
					if (s[i] >= 'A'&&s[i] <= 'Z'&&a3 > 1)
					{
						s[i] = '1'; break;
					}
				}
			}
			if (!a2)
			{
				for (int i = 0; i < s.length(); i++)
				{
					if (s[i] >= 'A'&&s[i] <= 'Z'&&a3 > 1)
					{
						s[i] = 'a'; break;
					}
					if (s[i] >= '0'&&s[i] <= '9'&&a1 > 1)
					{
						s[i] = 'a'; break;
					}
				}
			}
			if (!a3)
			{
				for (int i = 0; i < s.length(); i++)
				{
					if (s[i] >= 'a'&&s[i] <= 'z'&&a2 > 1)
					{
						s[i] = 'A'; break;
					}
					if (s[i] >= '0'&&s[i] <= '9'&&a1 > 1)
					{
						s[i] = 'A'; break;
					}
				}
				
			}cout << s << endl;
				continue;
		}
		if (a1)
		{
			s[0] = 'a', s[1] = 'A';
		}
		if (a2)
		{
			s[0] = '0', s[1] = 'A';
		}
		if (a3)
		{
			s[0] = '0', s[1] = 'a';;
		}
		cout << s << endl;
		continue;
	}
}