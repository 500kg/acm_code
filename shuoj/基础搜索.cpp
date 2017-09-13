#include<bits/stdc++.h>
using namespace std;
const int maxN=32;
int m,n,k,mm;
char a[maxN][maxN][maxN];
int vis[maxN][maxN][maxN];

int dfs(int x,int y,int z,int mmm)
{
    printf("%d %d %d\n",x+1,y+1,z+1);
    if(mm)return 1;
    if(x<0||y<0||x>=m||y>=n||z<0||z>=k)return 2;
    if(vis[x][y][z]==1||a[x][y][z]=='#')return 3;
    if(a[x][y][z]=='E'){mm=mmm;return 4;}
    vis[x][y][z]=1;

    dfs(x,y,z+1,mmm+1);
    dfs(x-1,y,z,mmm+1);
    dfs(x+1,y,z,mmm+1);
    dfs(x,y-1,z,mmm+1);
    dfs(x,y+1,z,mmm+1);
    return 5;

}
int main()
{
    int i,j,p,xx,yy,zz;
    while(cin>>k>>m>>n)
    {
    getchar();
        mm=0;
        if(k==0&m==0&n==0)break;
        memset(vis,0,sizeof(vis));
        for(p=0;p<k;p++)
      {
          for(i=0;i<m;i++)
          {
             for(j=0;j<n;j++)
                {scanf("%c",&a[p][i][j]);putchar(a[p][i][j]);
                 if(a[p][i][j]=='S'){xx=p,yy=i,zz=j;}}
            getchar();
          }
          getchar();
      }
      printf("%d %d %d  11\n",xx,yy,zz);
       printf("%d", dfs(xx,yy,zz,0));
   //     printf("%d",vis[m-1][n-1]);
        if(mm)printf("Escaped in %d minute(s).\n",mm);
        else puts("Trapped!");

    }
}
