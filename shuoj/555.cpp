#include<iostream>
#include<stdio.h>
#include<math.h>
#include<cstring>
#include<cmath>
#include<stdlib.h>
using namespace std;
int a[25][20];
int v[25][20];
int main()
{
    int n,k;
    while(scanf("%d%d",&n,&k)==2)
    {


        for(int i=0;i<n;i++)
            for(int j=0;j<k;j++)
            scanf("%d",&a[i][j]);
        for(int i=1;i<n;i++)
            for(int j=0;j<k;j++)
        {
            v[i][j]=100000000;
            for(int t=0;t<k;t++)
                if(v[i][j]>v[i-1][t]+abs(a[i][j]-a[i-1][t]))
                v[i][j]=v[i-1][t]+abs(a[i][j]-a[i-1][t]);
        }
        int ans=100000;
        for(int i=0;i<k;i++)
            if(ans>v[n-1][i])
            ans=v[n-1][i];
        printf("%d\n",ans);

    }
}
