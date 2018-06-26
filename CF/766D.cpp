#include<bits/stdc++.h>
using namespace std;
map<string, int>M;
int fa[200050];
int R[200050];
int find(int x)
{
	if (fa[x] == x)return x;
	int fx = fa[x];
	fa[x] = find(fa[x]);
	R[x] = (R[x] + R[fx]) % 2;
	return fa[x];
}
void init()
{
	for (int i = 0; i <= 200000; i++)fa[i] = i, R[i] = 0;
}
void merge(int x, int y, int t)
{
	t--;
	int a = find(x), b = find(y);
	if (a == b)
	{
		int tmp = (R[x] - R[y] + 2) % 2;
		if (tmp == t)
		{
			cout << "YES" << endl;
			return;
		}
		else
		{
			cout << "NO" << endl;
			return;
		}
	}
	else
	{
		fa[b] = a;
		R[b] = (t + R[x] - R[y]) % 2;
		cout << "YES" << endl;
	}
}
int main()
{
	int n, m, q;
	cin >> n >> m >> q;
	init();
	for (int i = 1; i <= n; i++)
	{
		string s;
		cin >> s;
		M[s] = i;
	}
	for (int i = 0; i < m; i++)
	{
		int z;
		string a, b;
		cin >> z >> a >> b;
		int x = (M[a]);
		int y = (M[b]);
		merge(x, y, z);
	}
	for (int i = 0; i < q; i++)
	{
		string a, b; cin >> a >> b;
		int x = M[a], y = M[b];
		int fx = find(x), fy = find(y);
		if (fx != fy)cout << 3 << endl;
		else
		{
			int tmp = (R[x] - R[y] + 2) % 2;
			cout << tmp + 1 << endl;
		}
	}
}
