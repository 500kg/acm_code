#include<bits/stdc++.h>
using namespace std;

int main()
{
	int a[10000];
	int i;
	freopen("in.txt","r",stdin);
	int n,k;
	cin>>n>>k;
	for(int i = 0;i < n ;i++)
		cin>>a[i];
	sort(a,a+n);
	int ans=0;
	for(i=n-1;i>=0;i-=k)
		ans+=(a[i]-1)*2;
	cout<<ans;
}