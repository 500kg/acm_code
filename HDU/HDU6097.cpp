#include<bits/stdc++.h>
using namespace std;
const double eps = 1e-8;
struct point
{
	double x, y;
};
double dis(point a, point b)
{
	return sqrt((a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y));
}
int main()
{
	//freopen("in.txt", "r", stdin);
//	freopen("out.txt", "w", stdout);
	int T;
	cin >> T;
	point yd;
	yd.x = 0, yd.y = 0;
	while (T--)
	{
		double r;
		point a, b;
		scanf("%lf", &r);
		scanf("%lf%lf%lf%lf", &a.x, &a.y, &b.x, &b.y);double d = dis(a, yd);
		if (d<=eps)
		{
			printf("%.7f\n", 2 * r);
			continue;
		}
		
		double k = r*r / (d*d);
		point ra, rb, mid;
		ra.x = k*a.x;
		ra.y = k*a.y;
		rb.x = k*b.x;
		rb.y = k*b.y;
		mid.x = (ra.x + rb.x) / 2;
		mid.y = (ra.y + rb.y) / 2;
		double rd = dis(yd, mid), ans;
		if (rd <= r) //反演点连线与圆相交
			printf("%.7f\n", dis(ra, rb)*dis(yd, a) / r + eps);
		else
		{
			point temp;
			double rk =  r/ dis(yd, mid);
			temp.x = mid.x*rk;
			temp.y = mid.y*rk;
			printf("%.7f\n", 2 * dis(a, temp) + eps);
		}
			

	}
}