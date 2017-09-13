#include<stdio.h>
#include<string.h>
#define M 107
#define inf 0x3f3f3f
using namespace std;
int g[M][M],dis[M][M],path[M][M],pre[M];
int n,m,num,mincircle,count;
void init()
{
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            g[i][j]=dis[i][j]=inf;
        }
        g[i][i]=dis[i][i]=0;

    }
}
void Floyd()
{
    mincircle=inf;
    for(int k=1; k<=n; k++)
    {
        for(int i=1; i<k; i++)//求环
            for(int j=i+1; j<k; j++)
            {
                if(mincircle-dis[i][j]>g[i][k]+g[k][j])
                {
                    mincircle=dis[i][j]+g[i][k]+g[k][j];
                    num=0;
                    count=1;
                }
                else if(mincircle-dis[i][j]==g[i][k]+g[k][j])//记录次数
                    count++;
            }
        for(int i=1; i<=n; i++)//求最短路
            for(int j=1; j<=n; j++)
                if(dis[i][k]+dis[k][j]<dis[i][j])
                {
                    dis[i][j]=dis[i][k]+dis[k][j];
                }
    }

}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        init();
        int a,b,c;
        for(int i=1; i<=m; i++)
        {
            scanf("%d%d%d",&a,&b,&c);
            if(g[a][b]>c)
            {
                g[a][b]=g[b][a]=c;
                dis[a][b]=dis[b][a]=c;
            }
        }
        memset(path,0,sizeof(path));
        Floyd();
        if(mincircle==inf)
            printf("-1\n");
        else
            printf("%d %d\n",mincircle,count);

    }
    return 0;
}
