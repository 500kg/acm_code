#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=7;
const ll MOD=2147493647;
struct mat
{
    ll a[maxn][maxn];
    void clear()
    {
        memset(a,0,sizeof(a));
    }
    void init()
    {
        memset(a,0,sizeof(a));
        for(int i=0;i<maxn;i++)a[i][i]=1;
    }

};
mat mul(const mat &a,const mat &b)
{
    mat ans;
    ans.clear();
    for(int i=0;i<maxn;i++)
        for(int j=0;j<maxn;j++)
            for(int k=0;k<maxn;k++)
                ans.a[i][j]=(ans.a[i][j]+a.a[i][k]*b.a[k][j])%MOD;
    return ans;
}
mat pw2(mat a,ll n)
{
    mat ans;ans.init();
    while(n)
    {
        if(n&1)ans=mul(ans,a);
        a=mul(a,a);
        n>>=1;
    }
    return ans;
}
int main()
{
    int T;cin>>T;while(T--)
    {
       ll a,b,n;
       mat tmp;
       cin>>n>>a>>b;
       if(n==1)
       {
           printf("%lld\n",a);
           continue;
       }else if(n==2)
       {
           printf("%lld\n",b);
           continue;
       }
       tmp.clear();
       tmp.a[0][0]=1;
       tmp.a[0][1]=2;
       tmp.a[0][2]=1;
       tmp.a[0][3]=4;
       tmp.a[0][4]=6;
       tmp.a[0][5]=4;
       tmp.a[0][6]=1;

       tmp.a[1][0]=1;
       tmp.a[2][2]=1;
       tmp.a[2][3]=4;
       tmp.a[2][4]=6;
       tmp.a[2][5]=4;
       tmp.a[2][6]=1;

       tmp.a[3][3]=1;
       tmp.a[3][4]=3;
       tmp.a[3][5]=3;
       tmp.a[3][6]=1;

       tmp.a[4][4]=1;
       tmp.a[4][5]=2;
       tmp.a[4][6]=1;
       tmp.a[5][5]=1;
       tmp.a[5][6]=1;
       tmp.a[6][6]=1;

       tmp=pw2(tmp,n-2);
    /*   for(int i=0;i<maxn;i++)
       {
           for(int j=0;j<maxn;j++)
        cout<<tmp.a[i][j]<<' ';
        cout<<endl;
       }*/
    ll ans=0;
    ans=tmp.a[0][0]*b+tmp.a[0][1]*a;
    ans%=MOD;
    for(ll i=6,rua=1;i>=2;i--,rua*=2)
    {
        ans=(ans+1LL*rua*tmp.a[0][i])%MOD;;
    }
    printf("%lld\n",ans);
    }
}