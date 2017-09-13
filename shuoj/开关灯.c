#include<stdio.h>
#include<math.h>
int main()
{
    int n;
    double t;
    scanf("%d",&n);
    while(n--)
    {
        scanf("%lf",&t);
        printf("%d\n",(int)sqrt(t));
    }
}
