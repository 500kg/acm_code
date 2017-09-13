#include<bits/stdc++.h>
using namespace std;
const long long mod=1e9+7;
int main()
{
    long long f[10],x,y,n;
    while(cin>>x>>y>>n){
    f[1]=x;f[2]=y;f[3]=y-x;f[4]=-x;f[5]=-y;f[0]=x-y;
    cout<<(f[n%6]+1000*mod)%mod;}
}
