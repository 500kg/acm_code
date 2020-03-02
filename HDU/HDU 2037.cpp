#include<bits/stdc++.h>
using namespace std;
struct node
{
	int b, e;
}a[105];
int cmp(node a, node b)
{
	if (a.e < b.e)return 1;
	else if (a.e == b.e&&a.b > b.b)return 1;
	return 0;
}
int main()
{
	int n;
	while (scanf("%d", &n) == 1)
	{
	    if(n==0)break;
		for (int i = 0; i < n; i++)
			cin >> a[i].b >> a[i].e;
		sort(a, a + n, cmp);
		int ans = 0,now=0;
		for(int i=0;i<n;i++)
			if (a[i].b >= now)
			{
				now = a[i].e;
				ans++;
			}
		cout << ans << endl;
	}
	return 0;
}