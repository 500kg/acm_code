#include<stdio.h>
int f(int n)
{
    if(n==1)return 0;
    return f(n/2)+f(n-n/2)+n/2 * (n - n/2);

}
int main()
{
    int n,m;
    scanf("%d",&m);
    while(m--)
   {
       scanf("%d",&n);
        if(f(n)==0)printf("Mission Complete!\n");
      else if(f(n)==1)printf("Needs at least %d ATP!\n",f(n));
      else printf("Needs at least %d ATPs!\n",f(n));
   }

}
