#include<bits/stdc++.h>
using namespace std;
int t[52][52];
void f(int n)
{
    int j=n/2,i=0,k=1,p=n*n,pp;
    for(pp=1;pp<=p;pp++)
    {
        t[i][j]=k++;
        if(pp%n==0)i++;
         else  i--,j++;
        if(i<0)i=n-1;
        if(j>=n)j=0;
    }
}
int main()
{
    int n,cas=1;
    while(scanf("%d",&n)==1)
    {
        printf("Case %d:\n",cas++);
        f(n);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            printf("%5d",t[i][j]);
            printf("\n");
        }
    }
}
