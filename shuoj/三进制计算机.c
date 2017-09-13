#include<stdio.h>

int main()
{
    int n;
    long long int a,t;
    while(scanf("%d",&n)==1)
    {a=0;t=1;
        while(n>0)
            {
                a+=(n%3)*t;
                t*=10;
                n/=3;

            }
            printf("%lld\n",a);
    }
}
