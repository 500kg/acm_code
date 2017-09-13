#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
#define inf 9999999

int map[20][20];
int min_dis=inf;
void change(int x,int y)//翻转棋子
{
    map[x][y]=1-map[x][y];
    map[x+1][y]=1-map[x+1][y];
    if(x>0)
        map[x-1][y]=1-map[x-1][y];
    map[x][y+1]=1-map[x][y+1];
    if(y>0)
        map[x][y-1]=1-map[x][y-1];
}
int check()//查看是否是同一颜色
{
    int i,j;
    int cnt=0;
    for(i=0;i<4;i++)
        for(j=0;j<4;j++)
        cnt+=map[i][j];
    if(cnt==0||cnt==16)//棋盘为全白或全黑
        return 1;
    else
        return 0;
}
void search(int d,int step)
{
    int x,y;
    if(d==16)
    {
        if(check()&&step<min_dis)
            {
                min_dis=step;
            }
    }
    else
    {
        x=d/4;
        y=d%4;
        search(d+1,step);
        change(x,y);
        search(d+1,step+1);
        change(x,y);
    }
}
int main()
{
    char str;
    int i,j;
    for(i=0;i<4;i++)
        for(j=0;j<4;j++)
    {
        cin>>str;
        if(str=='b')
            map[i][j]=1;
        else
            map[i][j]=0;
    }
    search(0,0);
    if(min_dis == inf)
        printf("Impossible\n");
    else
        printf("%d\n",min_dis);
    return 0;
}
