#include<bits/stdc++.h>
using namespace std;
double dist(double x, double y)
{
	return sqrt(x*x + y*y);
}
int main()
{
	double r, d;
	scanf("%lf%lf", &r, &d);
	d = r - d;
	int T;
	scanf("%d", &T);
	int cnt = 0;
	while (T--)
	{
		double x1, y1, r1;
		scanf("%lf%lf%lf", &x1, &y1, &r1);
		double dis = dist(x1, y1);
			if (dis + r1 <= r&&dis - r1 >= d)
			cnt++;
	}
	printf("%d\n", cnt);
}