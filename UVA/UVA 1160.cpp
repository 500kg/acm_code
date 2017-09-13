#include<bits/stdc++.h>
using namespace std;
int f[100005];
int find(int x)
{
    if(x != f[x])f[x] = find(f[x]);
	return f[x];
}
void uni(int x,int y)
{
	int tx = find(x);
	int ty = find(y);
	if (tx != ty)f[ty] = tx;
}
bool same(int x, int y)
{
	int tx = find(x);
	int ty = find(y);
	//puts("RUA");
	return tx == ty;
}
void ini()
{
	for (int i = 0; i < 100005; i++)
		f[i] = i;
}
int main()
{
	int x, y;
	int ans = 0;
	ini();
	while (scanf("%d", &x) == 1)
	{
		if (x == -1){cout << ans << endl;ans=0;ini();continue;}
		cin >> y;
		if (same(x, y))
            ans++;
		else
            uni(x, y);
	}

	return 0;
}
