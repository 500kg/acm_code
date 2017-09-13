#include<stdio.h>
#define mod 1000000007
long long int f(long long int n)
{
    if(n==1||n==2)return 1;
    else return (f(n-1)%mod+f(n-2)%mod)%mod;
}
int main()
{
    long long int n;
  while  (scanf("%lld",&n)==1)
    printf("%    lld\n",f(n));
}
