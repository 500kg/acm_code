#include<iostream>
#include<stdio.h>
#include<math.h>
using namespace std;

int main()
{
    int n,i;
    double x;

    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%lf",&x);

        printf("Case %d: %d\n",i,(int)sqrt(x+1)-1);

    }
    return 0;
}
