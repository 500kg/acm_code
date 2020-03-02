#include<bits/stdc++.h>
using namespace std;

int main()
{
    int T;cin>>T;while(T--)
    {
        int a,b;scanf("%d%d",&a,&b);
        if(a>b)printf("%d\n",2*a+b);
        else printf("%d\n",a+2*b);
    }
}