#include<stdio.h>

int a,b;
int gcd(int x,int y)
{
    int r,tem;
    if(x>y){tem=x;x=y;y=tem;}
    while(y>0)
    {
        r=x%y;
        x=y;
        y=r;
    }
    return x;
}
long long int resss(int a,int b,int n)
{
    long long int t = 1;

    if (b == 0)
        return 1;

    if (b == 1)
         return a%n;

    t = resss(a, b>>1, n);

    t = t*t % n;

    if (b&0x1)
    {
        t = t*a % n;
    }

    return t;
 }
int main()
{
   while(scanf("%d%d",&a,&b))
  {
      printf("%d  ",resss(b,b,a));
   printf("%d  %d\n",gcd(a,resss(b,b,a)),gcd(a,b));
  }

/*
for(a=1;a<=100;a++)
    {printf("%d   ",gcd(a,resss(a,a,a)));
    printf("%d\n",resss(a,a,a));}*/
return 0;}
