#include<stdio.h>

int main()
{      int a,b;

int n,m,sum;
scanf("%d",&m);


scanf("%d",&n);
        sum=0;

        while(n--)
        {
            scanf("%d",&a);
            sum+=a;
        }
printf("%d",sum);

m--;
while(m--)
    {
       scanf("%d",&n);

        sum=0;

        while(n--)
        {
            scanf("%d",&a);
            sum+=a;
        }

printf("\n\n%d",sum);
    }
       return 0;
}
