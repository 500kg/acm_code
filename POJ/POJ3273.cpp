#include<iostream>
#include<stdio.h>
#include<string.h>
#include<cmath>
#include<algorithm>
using namespace std;
int n, m;
int a[100005];

int main()
{
	cin >> n >> m;
	int l = 0, r = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		r += a[i];
		l = max(l, a[i]);
	}
	while (l < r)    //二分搜索区间最大值的最小值
	{
		
		int mid = (l + r) / 2;
		int s = 0, cnt = 0;
	//	printf("%d %d %d\n", l, r, mid);
		for (int i = 0; i < n; i++)
		{
			s += a[i];
			if (s > mid)
				s = a[i], cnt++;
		}
		if (cnt < m)
			r = mid;
		else 
			l = mid + 1;
	}
	cout << r << endl;
}