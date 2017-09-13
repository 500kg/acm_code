#include<stdio.h>

int main()
{
    int a,sum,n;
    while(scanf("%d",&n)==1)
    {
        sum=0;

        while(n--)
        {
            scanf("%d",&a);
            sum+=a;
        }
        printf("%d\n",sum);
    }
return 0;
}
