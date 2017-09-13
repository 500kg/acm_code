#include<stdio.h>
char a[105];
int main()
{
    int i,n;
    scanf("%d%s",&n,a);

    int ans=0;

    for(i=0;i<n-1;i++)
         if(a[i]=='1')ans++;
    else break;

    printf("%d",ans+1);
}
