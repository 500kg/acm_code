#include<bits/stdc++.h>
using namespace std;
int solve(char a, char b)
{
	if (a == 'v')a = 1;
	else if (a == '<')a = 2;
	else if (a == '^')a = 3;
	else a = 4;
	if (b == 'v')b = 1;
	else if (b == '<')b = 2;
	else if (b == '^')b = 3;
	else b = 4;
	return (b - a + 4)%4;
}
int main()
{
	char a, c;
	scanf("%c %c", &a,&c);
	int n; cin >> n; n %= 4;
	int t = solve(a, c);
	int flag = 0, flag2 = 0;
	if (n == t)flag = 1;
	if ((n + t) % 4 == 0)flag2 = 1;
	if (flag&&flag2)puts("undefined");
	else if (flag)puts("cw");
	else puts("ccw");
}