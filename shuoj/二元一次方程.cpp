#include<bits/stdc++.h>
using namespace std;

int main()
{
    double a,b,c;
    while(scanf("%lf%lf%lf",&a,&b,&c)==3)
    {
        double x1=(-b+sqrt(b*b-a*4*c))/(2*a);
        double x2=(-b-sqrt(b*b-a*4*c))/(2*a);
        double x11=max(x1,x2),x22=min(x1,x2);
        printf("%.2f %.2f\n",x11,x22);
    }
    return 0;
}
