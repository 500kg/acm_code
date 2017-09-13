#include<iostream>
#include<cstring>
using namespace std;

int a[100],dp[100];
int n;
const int maxN=100000;
void solve()
{
    int res=0;
    memset(dp,0,sizeof(dp));
    for(int i=0;i<n;i++)
    {
        dp[i]=1;
        for(int j=0;j<i;j++)
            if(a[j]>a[i])
            dp[i]=max(dp[i],dp[j]+1);
        res=max(res,dp[i]);
    }
    cout<<res<<endl;
}
using namespace std;
int main()
{
    int T;
    cin>>T;while(T--)
    {
        cin>>n;
        for(int i=0;i<n;i++)
            cin>>a[i];
        solve();
    }
}
