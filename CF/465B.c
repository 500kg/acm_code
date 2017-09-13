#include<stdio.h>
int a[1005];
int main()
{
    int n,i,ans=0;
    scanf("%d",&n);
    scanf("%d",&a[0]);
    if(a[0]==1)ans++;
    for(i=1;i<n;i++)
       {
           scanf("%d",&a[i]);
           if(a[i]==1)ans++;
           else if(a[i-1]==1)ans++;
       }

       if(a[n-1]==0&&ans>0)ans--;
    printf("%d",ans);
}
