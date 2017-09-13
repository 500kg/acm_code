#include<bits/stdc++.h>
using namespace std;
long long ff(int n)
{
    long long a=1;
    while(a<=n)
        a*=10;
    return a;
}
int f(int n)
{
    long long a=n*n;
    if((a%ff(n))==n)return 1;
    else return 0;

}
int main()
{
    int n,cas=1;
    while(cin>>n)
    {
        printf("Case %d: %d, ",cas++,n);
        if(f(n))printf("Yes\n");
        else printf("No\n");
    }
}
