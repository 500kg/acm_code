#include<stdio.h>
int is7(n)
{int a;
    if(n%7==0)return 1;
    while(n>0)
    {
        a=n%10;
        if(a==7)return 1;
        n=n/10;
    }
    return 0;
}
int main()
{
    int m,n,i,cnt;
    while(scanf("%d%d",&m,&n)==2)
    {
        cnt=0;
        for(i=m+1;;i++)
        {

            if(is7(i))cnt++;

            if(cnt==n){printf("%d\n",i);break;}

        }
    }
}
