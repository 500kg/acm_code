#include<bits/stdc++.h>
using namespace std;
int pow_mod(int x,int n)
{
    int base=1;
    x%=10;
    while(n)
    {
        if(n&1)base=base*x%10;
        x=x*x%10;
        n>>=1;
    }
    base%=10;
    return base;
}
int main()
{

    int T;
    cin>>T;
    while(T--)
    {
        int n;
        scanf("%d",&n);
        cout<<pow_mod(n,n)<<endl;
    }
}
