#include<iostream>
#include<cmath>
#include<stdio.h>
using namespace std;
int main()
{
    int n,i,temp;
    while(scanf("%d",&n)==1)
    {
        temp=n;
        for(i=2;i*i<=n;i++)
        {
          if(n%i==0)
          {
              while(n%i==0) n=n/i;
              temp=temp/i*(i-1);
          }
          if(n<i+1)
              break;
        }
        if(n>1)
            temp=temp/n*(n-1);
        printf("%d\n",temp);
    }
    return 0;
}
