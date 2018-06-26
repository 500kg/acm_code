#include<bits/stdc++.h>
using namespace std;
string sub(string num1, string num2) {
	reverse(num1.begin(), num1.end());
	reverse(num2.begin(), num2.end());
	int len1 = num1.length(), len2 = num2.length();
	if (num1 == num2)return "0";
	string ans;
	int flag = 0;
	for (int i = 0; i < len2; i++)
	{
		int tmp = num1[i] - num2[i];
		tmp -= flag; flag = 0;
		if (tmp < 0)flag = 1,tmp+=10;
		ans.push_back(tmp + '0');
	}
//	cout << num1 << ' ' << num2 << endl;
//	cout << "RUA2" << ans << endl;

	for (int i = len2; i < len1; i++)
	{
		int tmp = num1[i] - '0';
		tmp -= flag; flag = 0;
		if (tmp < 0)flag = 1, tmp += 10;
		ans.push_back(tmp + '0');
	}
//	cout <<"RUA"<< ans << endl;
	int len = ans.length();
	for (int i = len - 1;; i--)
	{
		if (ans[i] != '0')
		{
			len = i; break;
		}
	}
//	cout << "RUA" << ans << endl;
	ans = ans.substr(0, len+1);
	//cout << "RUA" << ans << endl;
	reverse(ans.begin(), ans.end());
//	cout << "RUA" << ans << endl;
	return ans;
}
string cpy(string s,int a)
{
	string ans = s;
	int len = s.length();
	if (a)
	{
		for (int i = len - 2; i >= 0; i--)
			ans.push_back(s[i]);
	}
	else
	{
		for (int i = len - 1; i >= 0; i--)
			ans.push_back(s[i]);
	}
	return ans;
}
int main()
{
	int kase = 0;
	int T;
	cin >> T;
//	cout << sub("153", "62") << endl;
	while (T--)
	{
		string s;
		cin >> s;
		if (s == "10")
		{
			cout << "Case #" << ++kase << ":" << endl;//22136598
			cout << 2 << endl;
			cout << 8 << endl << 2 << endl;
			continue;
		}
		vector<string>ans;
		while(s.length()>1)//find the biggest palindromic string smaller than s
		{
			int len = s.length();
			string a = s.substr(0, (len + 1) / 2);
			a=cpy(a,len&1);
		//	cout << a << endl;
			if (a > s)
			{
				a = s.substr(0, (len + 1) / 2); //cout << a << endl;
		
				a = sub(a, "1"); //cout << a << endl;
	


				a = cpy(a, len & 1);
			}
		//	cout << a << endl;
			if(a!="0")
				ans.push_back(a);
			s = sub(s, a);
			//cout << s << endl;
		}
		if (s != "0")ans.push_back(s);
		cout << "Case #" << ++kase << ":" << endl;//22136598
		cout << ans.size() << endl;
		for (int i = 0; i < ans.size(); i++)
			cout << ans[i] << endl;
	}

}