#include <bits/stdc++.h>


int main()
{
    int n,tem;
    while(scanf("%d",&n)==1)
    {
        int w,s,sum=0,min=1000000000;
        while(n--)
        {

            scanf("%d%d",&w,&s);
            if(w>s){tem=w;w=s;s=tem;}
            if(sum-s<min&&sum-s>0)min=sum-s;
            sum+=w;


        }
        printf("%d\n",min);
    }
}
