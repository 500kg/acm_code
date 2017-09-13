#include<bits/stdc++.h>
using namespace std;
const int MAXN=10000;
const int MOD=1e9+7;
int fact[MAXN];
int mod_fact(int n,int p,int &e)
{
    e=0;
    if(n==0)return 1;
    int res=mod_fact(n/p,p,e);
    e+=n/p;
    if(n/p%2!=0)return res*(p-fact[n%p])%p;
    return res*fact[n%p]%p;
}

int main()
{
    int n;
    int e;
  //  for(int i=1;i<=1000;i++)
   //     fact[i]=mod_fact(i,MOD,e);
    while(cin>>n)
    {
        cout<<mod_fact(n,3,e)<<endl;
    }
  return 0;
}
