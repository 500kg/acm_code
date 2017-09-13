#include<bits/stdc++.h>
using namespace std;
int a[105];
int b[105];

int main()
{
    int n,m,i;
    while(cin>>n>>m)
    {
        memset(b,1,sizeof(b));
        memset(a,0,sizeof(a));
        for(i=1;i<=n;i++)
            cin>>a[i];
        int t=0;      //第t个
        int now=1;
        int flag=m;   //第flag个滚
        int num=n;  //人数-1
        while(1)
        {


                if(b[now])
                {
                    t++;
                }
                if(t==flag)
                {
                    flag=a[now];
                    t=0;
                    b[now]=0;
                   // printf("%d gg\n",now);
                    num--;
                    if(num==0)break;
                }

            now++;
            if(now>n)now=1;

        }
        printf("%d\n",now);
    }

}
