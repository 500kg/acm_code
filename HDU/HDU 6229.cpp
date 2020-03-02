#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> PII;
typedef long long ll;
map<PII, int> M;
int fx[] = { -1,0,1,0 };
int fy[] = { 0,1,0,-1 };
int n, k;
ll UP, DO;
int what(int x, int y)
{
	if ((x == 0 || x == n - 1) && (y == 0 || y == n - 1))return 3;
	if (x == 0 || y == 0 || x == n - 1 || y == n - 1)return 4;
	return 5;
}
void DEL(int x, int y)
{
	if (x + y < n - 1)
	{
		if (M.count({ x, y }))UP -= M[{x, y}];
		else UP -= what(x, y);
		M[{x, y}] = 0;

	}
	else
	{
		if (M.count({ x,y }))DO -= M[{x, y}], M[{x, y}] = 0;
		else DO -= what(x, y);
		M[{x, y}] = 0;
	}
}
void minu(int x, int y)
{
	if (M.count({ x,y }) && M[{x, y}] == 0)return;
	if (x + y < n - 1)
	{
		UP--;
		if (M.count({ x,y }))M[{x, y}]--;
		else M[{x, y}] = what(x, y) - 1;
	}
	else
	{
		//	if (M.count({ x,y }) && M[{x, y}] == 0)return;
		DO--;
		if (M.count({ x,y }))M[{x, y}]--;
		else M[{x, y}] = what(x, y) - 1;
	}
}
ll gcd(ll a, ll b)
{
	if (!b)return a;
	return gcd(b, a%b);
}
bool ok(int x, int y)
{
	if (x < 0 || y < 0)return 0;
	if (x >= n || y >= n)return 0;
	return 1;
}
int main()
{
	int kase = 0;
	int T; cin >> T; while (T--)
	{
		cin >> n >> k;
		int x, y;
		M.clear();
		UP = 3LL + 8LL * (n - 2) + 5LL * (n - 2)*(n - 3) / 2, DO = 9LL + 8LL * (n - 2) + 5LL * (n - 2)*(n - 1) / 2;
		while (k--)
		{
			scanf("%d%d", &x, &y);
			DEL(x, y);
			for (int i = 0; i < 4; i++)
				if (ok(x + fx[i], y + fy[i]))
					minu(x + fx[i], y + fy[i]);
		}

		ll G = gcd(UP, DO);
		UP /= G; DO /= G;
		printf("Case #%d: %lld/%lld\n", ++kase, DO, UP + DO);
	}
}