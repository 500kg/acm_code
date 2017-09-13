#include<stdio.h>
int a[100005],vis[100005];
int main()
{
    int n,d,b,i,j,x,flag,t;
    scanf("%d%d%d",&n,&d,&b);
    for(i=0;i<n;i++)  scanf("%d",&a[i]);
    for(i=0;i<n;i++)
    {
        flag=0;
        if(vis[i]==1)continue;
        for(j=0;j<n;j++)
        {


            if((a[i]+a[j])==b){flag=1;vis[i]=1;vis[j]=1;break;}            //等于b

        }
        if(flag)continue;
         for(j=0;j<n;j++)
        {

         if((a[i]+a[j])==d){flag=1;break;
         }             //等于a

        }
       // if(!flag){printf("NO");return 0;}

    }
    printf("YES\n%d",vis[0]);
    for(i=1;i<n;i++)
        printf(" %d",vis[i]);
}
