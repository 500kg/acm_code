#include<bits/stdc++.h>

using namespace std;
#define mod 1000000007
long long mypow(long long int x,long long int n,long long int t)
{
    long long int res=1;
    while(n>0)
    {
        if(n&1)res=res*x%t;
        x=x*x%t;;
        n>>=1;
    }
    return res;

}
int main()
{
    long long int m,n,t,i;
   /* while(scanf("%lld",&n)==1)
    printf("%lld\n",mypow(3,n,1071017));*/
    for(i=2;i<1071017;i++)
        if(1071017%i==0)
        printf("%d\n",i);
}
