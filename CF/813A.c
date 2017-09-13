#include<stdio.h>

int main()
{
    int n,r,sum=0,k,i;
    scanf("%d",&n);
    for(;n--;)
    {scanf("%d",&r);sum+=r;}
    scanf("%d",&n);
    for(;n--;)
    {
        scanf("%d%d",&k,&r);
        if(sum<=r){printf("%d",sum>k?sum:k);return 0;}
    }
    printf("-1");
    return 0;
}
