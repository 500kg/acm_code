#include<iostream>
#include<stdio.h>
#include<cstring>
#include<algorithm>
using namespace std;

const int maxn=5050;
struct point
{
    int x,y;
    point(){}
    point(int _x,int _y)
    {
        x=_x;
        y=_y;
    }
    point operator -(const point &b)const
    {
        return point (x-b.x,y-b.y);
    }
    point operator *(const point &b)const
    {
        return x * b.x + y * b.y;
    }
    point operator ^(const point &b)const
    {
        return x * b.y - y * b.x;
    }

};
struct Line
{
    point s,e;
    Line(){}
    Line(point _s,point _e)
    {

        s = _s; e = _e;
    }
}Line[maxn];
int ans[maxn];
int xmult(point p0, point p1, point p2)
{
    return (p1-p0)^(p2-p0);
}
int main()
{
    int n;
    bool first=true;
    while(scanf("%d"£¬&n)==1&&n)
    {
        if(first)first=false;
        else puts("");
        int m,x1,x2,y1,y2;
        scanf("%d%d%d%d%d",&m,&x1,&y1,&x2,&y2);
        int Ui, Li;
        for(int i = 0;i < n;i++)
        {
            scanf("%d%d",&Ui,&Li);
            Line[i]=line(point(Ui,y1),point (Li,y2));
        }
        Line[n]=Line(point(x2,y1),point(x2,y2));
        int x,y;
        point p;
        memset(ans,0,sizeof(ans));

    }
}
