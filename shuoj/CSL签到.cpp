#include<bits/stdc++.h>
using namespace std;
const int MOD=1000000007;
long long int p[200005];

void y()
{
    p[0]=1;p[1]=1;
    for(int i=2;i<=200000;i++)
       {
           p[i]=p[i-1]*i%MOD;
       }
}
long long f(int n)
{
    long long k1=p[10000],k2,tem;
    for(int i=200001;i<=n;i++)
        {k2=i*k1%MOD;
        tem=k2;
        k1=k2;}
    return k2;
}
int main()
{
    y();                      //进行预处理，对20万以下的数据可以直接输出答案
    int T,n;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
     printf("%lld\n",p[n]);

    }

}
