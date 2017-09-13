#include<bits/stdc++.h>
using namespace std;

int main()
{
    int h1,h2,m1,m2;
    int ans=0;
    scanf("%1d%1d:%1d%1d",&h1,&h2,&m1,&m2);
    while(1)
    {
        if(h1==m2&&h2==m1)
            break;
        ans++;m2++;
        if(m2==10){m1++,m2=0;}
        if(m1==6){m1=0,h2++;}
        if(h2==10){h1++,h2=0;}
        if(h1==2&&h2==4){h1=h2=0;}
    }


    printf("%d",ans);
}
