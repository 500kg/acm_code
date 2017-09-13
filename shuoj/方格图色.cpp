#include<bits/stdc++.h>
using namespace std;
int main()
{
    int i,n;
    long long f[65];
    f[1]=3;f[2]=f[3]=6;
    for(i=4;i<=60;i++)
    f[i]=f[i-1]+2*f[i-2];
    while(scanf("%d",&n)==1)
    {
        printf("%lld\n",f[n]);
    }
    /*for(i=1;i<60;i++)
        printf("%lld\n",f[i]);*/
}
