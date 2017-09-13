#include<bits/stdc++.h>
using namespace std;
int a[100];
int main()
{
    int n,s,i;
   while (cin>>n>>s){
        if(s==0&&n==1){
            printf("0 0");continue;
        }
    if(s<1||s>9*n){
        printf("-1 -1\n");continue;
    }
    a[0]=1;int sum=s-1;
    for(i=n-1;i>=0;i--)
    {
        if(sum>=9)a[i]=9,sum-=9;
        else if(sum<=0)break;
        else a[i]+=sum,sum=0;
    }
    for(i=0;i<n;i++)
        printf("%d",a[i]);
        printf(" ");
        memset(a,0,sizeof(a));
    for(i=0;i<n;i++)
    {
        if(s>=9)a[i]=9,s-=9;
        else if(s==0)break;
        else a[i]=s,s=0;
    }
    for(i=0;i<n;i++)
        printf("%d",a[i]);
        printf("\n");
}}
