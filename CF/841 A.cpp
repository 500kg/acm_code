#include<bits/stdc++.h>
using namespace std;
int a[200];
int main()
{
	int n, m;
	cin >> n >> m;
	memset(a, 0, sizeof(a));
	char ch[200];
	scanf("%s", ch);
	for (int i = 0; i < n; i++)
		a[ch[i]]++;
	int flag = 0;
	for (int i = 0; i < 200; i++)
		if (a[i] > m)
			flag = 1;
	if (flag)puts("NO");
	else puts("YES");
}