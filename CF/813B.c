#include<stdio.h>
long long int x,y,l,r;

int isyear(int i)
{
    long long int tem=1,rua=1;
    for(;;tem*=x)
    {
        rua=1;
        for(;;rua*=y)
            if(tem+rua==i||tem==i)return 0;
        else if(tem+rua>i)break;
        if(tem>i)break;
    }
    return 1;
}


int main()
{
    scanf("%lld%lld%lld%lld",&x,&y,&l,&r);
    long long int i,temp=0,max=0;
    for(i=l;i<=r;i++)
    {
        if(isyear(i))
        {temp++;
        max=max>temp?max:temp;}
        else temp=0;
    }
    printf("%I64d",max);

}
