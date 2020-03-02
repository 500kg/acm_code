#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD=1e9+7;
const int maxn=1e5+50;
ll inv[maxn];
ll pro[maxn];
ll rua[maxn];
int main()
{
    inv[1]=pro[1]=1;
    for(int i=2;i<=100000;i++)inv[i]=(-MOD/i*inv[MOD%i]%MOD+MOD)%MOD;
    for(int i=2;i<=100000;i++)pro[i]=pro[i-1]*i%MOD;

    int T;cin>>T;while(T--)
    {
        ll n;scanf("%lld",&n);
        if(n<=4){printf("%lld\n",n);continue;}
        ll l=1,r=50000;
        ll pos;
        while(l<=r)
        {
      //      cout<<l <<' '<<r<<endl;
            ll mid=l+r>>1;
            ll tmp=(3LL+mid)*mid/2;
            if(tmp<=n)
            {
                l=mid+1;
                pos=mid;
            }else r=mid-1;
        }
   //     cout<<pos<<endl;
        pos++;
        if((3LL+pos)*(pos)/2==n+1)
        {
            printf("%lld\n",pro[pos+2]*inv[2]%MOD*inv[pos+1]%MOD);
        }
        else
        {
            ll ans=pro[pos+1];
            ll cnt=n-(2LL+pos)*(pos-1)/2;
            cnt=pos+1-cnt;
            ans=ans*inv[cnt]%MOD;
            printf("%lld\n",ans);
        }
    }
}