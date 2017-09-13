#include<bits/stdc++.h>
using namespace std;
#define  V 1500
int f[V];
int w[105];
int num[105];
int dp[1000];
int main()
{

    int t,m,n,v;
    while(scanf("%d%d",&n,&v)==2)
    {
        memset(dp,0,sizeof(dp));
        for (int i=1;i<=n; i++)
    {
        cin>>w[i]>>num[i];
    }
    for(int i=1;i<=n;++i){
	  for(int j=1;j<=num[i];++j){
		for(int k=v;k>=0;--k){
			if(k>=j*w[i]){dp[k] = max(dp[k],dp[k-j*w[i]]+k*w[i]);printf("%d %d\n",dp[k],k);}
		}
	}
}

    cout<<dp[1]<<endl;
    }
}
