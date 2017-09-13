#include<stdio.h>
//long long f[65];
//f[1]=3,f[2]=f[3]=6;
long long f(int n)
{
    int i;
    long long result=0;
    long long f1 = 6;
    long long f2 = 6;
    for(i=n-3;i>0;i--)
        {
            result=f2+f1*2;
            f1=f2;
            f2=result;
        }
}
 int main()
{
    int n,i;
    while(scanf("%d",&n)==1)
    {
        if(n==1)printf("3\n");
        else if(n==2||n==3)printf("6\n");
        else
        printf("%lld\n",f(n));
    }
    /*for(i=1;i<=60;i++)
        printf("%lld\n",f(i));*/
    return 0;
}
