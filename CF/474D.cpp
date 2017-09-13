#include<bits/stdc++.h>
using namespace std;
const int maxN=1e5+5;
const int mod=1e9+7;
long long dp[maxN],s[maxN];
void ini(int k)
{
    int i;
    dp[0]=0;
    for(i=1;i<k;i++)
        dp[i]=1;
    dp[k]=2;
    for(i=k+1;i<=maxN;i++)
        dp[i]=(dp[i-1]+dp[i-k])%mod;
    for(i=1;i<=maxN;i++)
        s[i]=(s[i-1]+dp[i]);
}
int main()
{
   // freopen("in.txt","r",stdin);
    int T,k;
    cin>>T>>k;
    ini(k);
    while(T--)
    {
        int l,r;
        cin>>l>>r;
        long long ans=(s[r]-s[l-1])%mod;
        cout<<ans<<endl;
    }
}
