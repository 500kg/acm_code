#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll>a;
ll x,y,l,r,ans=0;
int main(){
	ios::sync_with_stdio(false);cin>>x>>y>>l>>r;
	a.push_back(l-1);a.push_back(r+1);
	for(ll i=1;;i*=x){
		for(ll j=1;;j*=y){
			ll len=i+j;
			if(len>=l&&len<=r)a.push_back(i+j);
			if(j>r/y)break;
		}
		if(i>r/x)break;
	}
	sort(a.begin(),a.end());
	for(ll i=1;i<a.size();i++)ans=max(ans,a[i]-a[i-1]-1);
	cout<<ans<<endl;
}
