#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstdio>
using namespace std;

int Exgcd(int a, int b, int &x, int &y) {
	if (b == 0) {
		x = 1;
		y = 0;
		return a;
	}
	int d = Exgcd(b, a%b, x, y), temp = x;
	x = y;
	y = temp - a / b*y;
	return d;
}

void solve(int a, int b, int d, int& g, int& x, int& y) {
	g = Exgcd(a, b, x, y);
	x *= d / g;
	int t = b / g;
	x = (x%t + t) % t;
	y = abs((a*x - d) / b);
}

int main() {
	int a, b, d, g, x1, x2, y1, y2;
	while (scanf("%d%d%d", &a, &b, &d) == 3)
	{
		if (a == 0 && b == 0 && d == 0)break;

		solve(a, b, d, g, x1, y1);
		solve(b, a, d, g, x2, y2);

		if (x1 + y1 < x2 + y2)
			printf("%d %d\n", x1, y1);
		else
			printf("%d %d\n", y2, x2);
	}
	return 0;
}
