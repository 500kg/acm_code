#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
const int MOD = 10000;
struct Ma
{
	int a[2][2];
}A,I;
void ini()
{
	memset(I.a, 0, sizeof(I.a));
	I.a[0][0] = I.a[1][1] = 1;
	memset(A.a, 0, sizeof(A.a));
	A.a[0][0] = A.a[0][1] = A.a[1][0] = 1;
}
Ma mul(Ma x, Ma y)
{
	Ma res;
	memset(res.a, 0, sizeof(res.a));
	for (int i = 0; i<2; i++)
		for (int j = 0; j<2; j++)
			for (int k = 0; k<2; k++)
			{
				res.a[i][j] += x.a[i][k] * y.a[k][j];
				res.a[i][j] %= MOD;
			}
	return res;
}
long long f(int n)
{
	Ma M = A, res = I;
	while (n)
	{
		if (n & 1)
			res = mul(res, M);
		M = mul(M, M);
		n >>= 1;
	}
	return res.a[0][1];
}
int main()
{
	int n;
	ini();
	while (scanf("%d", &n) == 1)
	{
		if (n == -1)return 0;
		cout << f(n) << endl;
	}
}