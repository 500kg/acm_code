#include<iostream>
#include<stdio.h>
using namespace std;


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
int main()
{
    int a,b;
    while(scanf("%d%d",&a,&b)==2)
    {
        printf("%d\n",a*b/gcd(a,b));
    }
}
