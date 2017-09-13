#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
const int maxn = 100500;
const int strl = 100500;

struct node
{
	int id, vis;
}t[maxn];
int properfrac2str(long long numerator, long long denominator, int radix)
{
	memset(t, 0, sizeof(t));
	const char table[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	int i = 0;
	if (numerator == 0 || strl <= 1)
	{
		return 0;
	}
	t[numerator].vis = 1;
	t[numerator].id = 0;
	for (i = 0; i < strl - 3; i++)
	{
		numerator *= radix;
		numerator %= denominator;

		if (numerator == 0)
		{
			break;
		}
		if (t[numerator].vis)
		{
			return i - t[numerator].id + 1;
		}
		t[numerator].vis = 1;
		t[numerator].id = i + 1;
	}
	return 0;
}
int cal(char c)
{
	if (c >= '0'&&c <= '9')
		return c - '0';
	else if (c >= 'A'&&c <= 'Z')
		return c - 'A' + 10;
	else return c - 'a' + 10;
}
long long  Gcd(long long a, long long b)
{
	if (b == 0)
		return a;
	return Gcd(b, a % b);
}
int main()
{
	int T;
	cin >> T;
	int kase = 0;
	while (T--)
	{
		char up[100];
		char down[100];
		int base;
		scanf("%d%s%s", &base, up, down);
		long long nup = 0, ndown = 0;
		for (int i = 0; down[i] != '\0'; i++)
		{
			ndown = ndown*base + cal(down[i]);
		}
		for (int i = 0; up[i] != '\0'; i++)
		{
			nup = nup*base + cal(up[i]);
			nup %= ndown;
		}
		long long tmp = Gcd(nup, ndown);
		nup /= tmp, ndown /= tmp;
		printf("Scenario #%d:\n", ++kase);
		printf("%d\n\n", properfrac2str(nup, ndown, base));
		
	}
}