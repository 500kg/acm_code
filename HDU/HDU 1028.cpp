#include<iostream>
#include<string>
#include<cstring>
#include <bits/stdc++.h>
using namespace std;
long long c[150][150];
int coun(int m, int n);
int main() {
	int m, n;
	memset(c, -1, sizeof(c));
	while (scanf("%d", &m) == 1) {

		int res = coun(m, m);
		printf("%d\n", res);
	}
	return 0;
}
int coun(int m, int n) {
	if (c[m][n] != -1)return c[m][n];
	if (m == 0 || n == 1)
		return 1;
	if (n > m)
	{
	//	printf("%d\n", coun(m, m));
		return c[m][n]=coun(m, m);
	}

	else
	{

		return c[m][n]=coun(m, n - 1) + coun(m - n, n);
	}
}
