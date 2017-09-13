#include<bits/stdc++.h>

using namespace std;
int a,b,c,d,i,k,x,y,flag;




int main()
{
    int n;
    scanf("%d",&n);
    while(n--)
    {
        flag=1;
        scanf("%d%d%d%d",&a,&b,&c,&d);
        x=max(b,d)+a*c;
        for(i=max(b,d);i<=x;i++)
            if((i-b)%a==0&&(i-d)%c==0)
        {printf("%d\n",i);flag=0;break;}
        if(flag)printf("-1\n");
    }
    return 0;
}
