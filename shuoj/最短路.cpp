#include<bits/stdc++.h>
using namespace std;
struct edge
{
    int from,to,cost;
};
edge es[1005];
int dist[2005],prev[1005];
int n,table[1005][1005],E;

void Dijkstra(int n,int v,int dist[],int prev[],int **table){
    //其中n指n个节点,v指起点,dist[i]记录源点到i点的最短特殊路径,prev[i]记录在特殊路径当中i点的前一个点,table[][]就是无向图的邻接矩阵
    int i,j,k;
    bool s[10000];   //maxint是个非常大的数
    for (i=1;i<=n;++i)
    {
        dist[i] = table[v][i];
        s[i] = false;
        if (dist[i] == 10000) prev[i] = 0;   //将该点的前一个点赋为0,应为它不与v点直接相连
        else     prev[i] = v;
     }
     dist[v] = 0; s[v] = true;      //与prim不同的是初始时从源点出发
     for (i=1;i<n;++i)
     {
         int temp = 10000;
         int u = v;
         for (j=1;j<=n;++j)
         {
              if ((!s[j])&&(dist[j]<temp))
              {
                    u = j;
                    temp = dist[j];
               }
         }
         s[u] = true;
         for (j=1;j<=n;++j)
         {
              if ((!s[j])&&table[u][j]<10000)
              {
                 int newdist = dist[u] + table[u][j];     //newidist为从源点到该点的最短特殊路径
                 if (newdist<dist[j])
                 {
                      dist[j] = newdist;
                      prev[j] = u;
                  }
              }
          }
      }

}
int main()
{
    int u,v,t;
    while(scanf("%d%d",&E,&n)==2)
    {
        for(int i=0;i<E;i++)
            {scanf("%d%d%d",&u,&v,&t);
             table[u][v]=table[v][u]=t;
            }
Dijkstra(n,0,dist,prev,&&table);
    }
}
