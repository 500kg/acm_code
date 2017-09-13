#include<bits/stdc++.h>
using namespace std;
int n,k,q,a[1000000],b[1000000],x,y;
int main(){
	ios::sync_with_stdio(false);
	cin>>n>>k>>q;
	for (int i=1;i<=n;i++)cin>>x>>y,a[x]++,a[y+1]--;
	for (int i=1;i<=200000;i++)a[i]+=a[i-1],b[i]=(a[i]>=k)+b[i-1];
	for (int i=1;i<=q;i++){
		cin>>x>>y;cout<<b[y]-b[x-1]<<endl;
	}
}
