#include<iostream>
#include<stdio.h>
#include<math.h>
#include<cstring>
#include<cmath>
#include<stdlib.h>
using namespace std;
int a[105],b[105];
int m[105][105];
bool used[105];
int pipei[105];
int N,M,i,j;
int d(int x)
{
    for(int i=0;i<N;i++)
    {
        if(used[i]&& m[x][i]==1)
        {
            used[i]=1;
            if(pipei[i]==-1||d(pipei[i]))
            {
                pipei[i]=x;
                return 1;
            }
        }
    }
    return 0;
}

int main()
{
    int n,k=1;
    scanf("%d",&n);
    while(n--)
    {
        memset(pipei,-1,sizeof(pipei));
        memset(m,0,sizeof(m));

        scanf("%d",&N);
        for(i=0;i<N;i++)
            scanf("%d",a+i);
        scanf("%d",&M);
        for(i=0;i<M;i++)
            scanf("%d",b+i);


        for(i=0;i<N;i++)
            for(j=0;j<M;j++)
        {
            if(b[j]%a[i]==0)m[j][i]=1;
        }
        int ans=0;
         for(i=0;i<M;i++)
          {
              memset(used,0,sizeof(used));
              ans+=d(i);
          }
        printf("Case %d: %d\n", k++,ans);
    }
}
