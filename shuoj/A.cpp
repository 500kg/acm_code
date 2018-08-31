#include<bits/stdc++.h>
using namespace std;
unsigned  A, B, C;
int n;
unsigned x = A, y = B, z = C;
typedef __int128 ll;
unsigned tang()
{
	unsigned t;
	x ^= x << 16;
	x ^= x >> 5;
	x ^= x << 1;
	t = x;
	x = y;
	y = z;
	z = t ^ x^y;
	return z;
}
ll gcd(ll a, ll b)
{
	if (!b)return a;
	return gcd(b, a%b);
}
ll lcm(ll a, ll b)
{
	if (a == 0 || b == 0)return 0;
	return a / gcd(a, b)* b;
}
int main()
{
	int T;
	cin >> T;
	int kase = 0;
	while (T--)
	{
		scanf("%d%d%d%d", &n, &A, &B, &C);
		x = A, y = B, z = C;
		ll maxi[25];
		memset(maxi, 0, sizeof(maxi));
		for (int i = 0; i < n; i++)
		{
			ll now = tang();
	//		now = rand() % 50;
			for (int j = 0; j < 20; j++)
			{
				if (now > maxi[j])
				{
					for (int k = 19; k > j; k--)
						maxi[k] = maxi[k - 1];
					maxi[j] = now;
					break;
				}
			}
		}
	    ll ans = 0;

		for (int i = 0; i < 20; i++)
		{
			for (int j = i + 1; j < 20; j++)
				ans = max(ans, lcm(maxi[i], maxi[j]));
		}
	//	cout << lcm(4000000000, 4000000000 - 1);
		printf("Case #%d: \n", ++kase);

		char s[50];
		void myitoa(__int128_t v, char* s)
		{
			char temp;
			int i = 0, j;

			while (v >0) {
				s[i++] = v % 10 + '0';
				v /= 10;
			}
			s[i] = '\0';

			j = 0;
			i--;
			while (j < i) {
				temp = s[j];
				s[j] = s[i];
				s[i] = temp;
				j++;
				i--;
			}
		}
		cout << s << endl;

	}
}
