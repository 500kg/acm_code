#include<bits/stdc++.h>
using namespace std;
const int MOD=1000000007;
typedef long long ll;
int sum(ll x)
{
    int i=0;
    while(x)
    {
        i=i+x%10;
        x/=10;
    }
    return i;
}
int main()
{
    ll n,m,i;
    while(scanf("%lld%lld",&n,&m)==2)
    {
        ll ans=0,aass=0;
      /* for(i=1;i<=n;i++)
            if(i-sum(i)>=m)aass++;*/           //最朴素的方法10^18显然会超时
      for(i=1;i<=n-m;i++)
        if(i>162){ans=ans+n-m-162;break;} else        //移项得x-m>=sum(x),令i=x-m.当i>=163=9*18时i一定大于等于sum(i+x)
        if(i>=sum(m+i))ans++;

        printf("%lld\n",ans);
    }

}
