#include<stdio.h>
int a,p;
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
 int isprime(int n)
 {
     int i;
     if(n==2)return 1;
     for(i=2;i<n/2;i++)
        if(n%i==0)return 0;
     return 1;
 }
int main()
{
    long long int ress,res;

    while(scanf("%d%d",&p,&a)==2)
    {

        if(isprime(p)==1)
        {
            printf("no\n");continue;
        }
        res=a%p;
        ress=resss(a,p,p)%p;
      //  printf("%d %d\n",res,ress);
        if(res==ress)printf("yes\n");
        else printf("no\n");
    }
}
