#include<stdio.h>

int n,b;
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
int jie(int k)
{
    if(k==1)return b;
    return (jie(k/2)%10000000)*(jie(k-k/2)%10000000)%10000000;
}
int main()
{
    int a;
   while(scanf("%d%d",&a,&b))
  {

   printf("%d\n",gcd(a,jie(b)););


}return 0;}
