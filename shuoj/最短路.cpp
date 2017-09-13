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
    //����nָn���ڵ�,vָ���,dist[i]��¼Դ�㵽i����������·��,prev[i]��¼������·������i���ǰһ����,table[][]��������ͼ���ڽӾ���
    int i,j,k;
    bool s[10000];   //maxint�Ǹ��ǳ������
    for (i=1;i<=n;++i)
    {
        dist[i] = table[v][i];
        s[i] = false;
        if (dist[i] == 10000) prev[i] = 0;   //���õ��ǰһ���㸳Ϊ0,ӦΪ������v��ֱ������
        else     prev[i] = v;
     }
     dist[v] = 0; s[v] = true;      //��prim��ͬ���ǳ�ʼʱ��Դ�����
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
                 int newdist = dist[u] + table[u][j];     //newidistΪ��Դ�㵽�õ���������·��
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
