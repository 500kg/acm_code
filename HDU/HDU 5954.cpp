#include<bits/stdc++.h>
using namespace std;
const double pi = acos(-1);
const double eps = 1e-12;

double f1(double x)
{
    double p = cos(asin(x));
    return p * p * p;
}

double f2(double x)
{
    double aco = acos(x);
    return x * aco - sin(aco);
}

int main()
{
    double h;
    int T;
    scanf("%d", &T);
    while (T--)
    {
        cin >> h;
        if (h == 0)
        {
            printf("%.5f\n",0.0);
            continue;
        }
        if (h >= 1.0)
        {
            double a = sqrt(1.0 + (2.0 - h) * (2.0 - h));
            double ans = pi * a;
            printf("%.5f\n", ans);
        }
        else
        {
            double V = pi * h;
            double l = 0, r = 2;
            int ks = 1;
            while (ks <= 10000)
            {
                double a = (r + l) / 2;
                double ret = 2 / (3 * a) * (f1(1 - a) - f1(1)) + 2 / a * (f2(1 - a) - f2(1));
                ret = abs(ret);
                //printf("l %lf r %lf ret : %f\n", l, r, ret);
                if (abs(ret - V) < eps)
                    break;
                if (ret < V)
                {
                    l = a;
                }
                else
                {
                    r = a;
                }
                ks++;
            }
            double a = (l + r) / 2.0;
            double xita = atan(2.0 / a);
            double ans = (1 - a) * sin (acos(1 - a)) - acos(1 - a);
            ans = abs(ans);
            ans /= cos(xita);
            printf("%.5f\n", ans);
        }
    }
    return 0;
}