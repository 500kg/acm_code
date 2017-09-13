#include<bits/stdc++.h>
using namespace std;
const long long mod=1e9+7;
long long po(long long n)
{

    long long res=1,base=2;
    while(n)
    {
        if(n&1)
            res=base*res%mod;
        base=base*base%mod;   //wa
        n>>=1;
    }
    return res;
}
int main()
{
    long long n;
    while(cin>>n)
        if(n>=1)
        cout<<po(n-1)*(po(n)+1)%mod<<endl;
    else cout<<1<<endl;    //tle
}
