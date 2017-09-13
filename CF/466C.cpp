#include<bits/stdc++.h>
#define ll long long int
using namespace std;
long long n,a[500005],z,ans;
int32_t main()
{
   cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i]; a[i]=a[i]+a[i-1];
	}
	for(int i=0;i<n-1;i++){
		if(a[i]*3==a[n-1]*2)ans=ans+z;
		if(a[i]*3==a[n-1])z++;
	//	printf("%lld %lld\n",ans,z);
	}
//	for(int i=0;i<n;i++)
 //       printf("%lld   ",a[i]);
	cout<<ans;

}
