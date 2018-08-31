#include<bits/stdc++.h>
using namespace std;
int solve(int n,int k)
{
    int now;
    if(n==k) return n;
    now=solve(n-n/k,k);
    return ((now-1)/(k-1)+now);
}
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int ans,n,k;
        cin>>n>>k;
        ans=solve(n,k);
        cout<<ans<<endl;
    }
}
