#include<bits/stdc++.h>
using namespace std;
double Pi = acos(-1.0);
int main()
{
	int T;
	cin >> T;
	int kase = 0;
	int a = 1;
	while (T--)
	{
		Pi = acos(-1.0);
		double R;
		int n;
		scanf("%lf%d", &R, &n);
		double an = Pi / n;
		printf("Scenario #%d:\n", ++kase);
		printf("%.3f\n\n", R*sin(an) / (1 + sin(an)));
	}
}