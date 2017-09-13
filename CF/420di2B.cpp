#include<bits/stdc++.h>
long long f(int x,int y)
{
    long long ans;
    ans=(1+y)*x*(1+x)/2+(1+y)*y*(1+x)/2;
    return ans;
}
using namespace std;
int main()
{
    int m,b,p,q,i,j;
    scanf("%d%d",&m,&b);
    long long ans=0,tem;
    int y=b,x=m*b;
    long long squ=0;
    for(i=0;i<=x;i++)
    {ans=max(ans,f(i,(b*m-i)/m));
    printf("%lld %d %d\n",ans,i,(b*m-i)/m);
    }
printf("%I64d",ans);
}
