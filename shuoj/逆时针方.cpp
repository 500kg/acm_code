#include<bits/stdc++.h>
using namespace std;
int a[105][105];
void f(int n)
{
    int p=n*n,i=0,j=0,k=1;
    int flag=0;
    for(k=1;k<=p;k++)
    {
        a[i][j]=k;
        if(flag==0)i++;
        else if(flag==1)j++;
        else if(flag==2)i--;
        else j--;
        if(a[i][j]||i>=n||j>=n||i<0||j<0)
        {if(flag==0)i--,j++;
        else if(flag==1)j--,i--;
        else if(flag==2)i++,j--;
        else j++,i++;
            flag++;if(flag==4)flag=0;}
       // printf("%d %d %d %d\n",a[i][j],i,j,flag);
    }
}
int main()
{
    int n;
    while(scanf("%d",&n)==1)
    {
        memset(a,0,sizeof(a));
        f(n);
        for(int i=0;i<n;i++)
        {
            printf("%d",a[i][0]);
            for(int j=1;j<n;j++)
                printf(" %d",a[i][j]);
            printf("\n");
        }
printf("\n");
    }
}
