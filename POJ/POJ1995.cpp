#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
int M,n;
long long pow_mod(int a,int n)
{
    long long res=1,base=a;
    while(n)
    {
        if(n&1)res = ( res * base ) % M;
        base = (base *base )%M;
        n>>=1;
    }
    return res;
}
int main()
{
    int T;cin>>T;while(T--)
    {

        cin>>M>>n;
        long long ans=0;
        int a,b;
        for(int i=0;i<n;i++)
        {
            cin>>a>>b;
            ans = ( ans + pow_mod (a , b)) % M;
        }
        cout<<ans<<endl;

    }
}
