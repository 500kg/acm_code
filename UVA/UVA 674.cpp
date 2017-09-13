#include<bits/stdc++.h>
using namespace std;
int dp[7505][5];
int coin[5]={1,5,10,25,50};
void ini()
{
    memset(dp,0,sizeof(dp));
    int i,j,k;
    for(i=0;i<=7500;i++)
        dp[i][0]=1;
    for(i=0;i<5;i++)
        dp[0][i]=1;
        for(j=1;j<5;j++)
    for(i=1;i<=7500;i++)

            for(k=0;k*coin[j]<=i;k++)
            dp[i][j]+=dp[i-k*coin[j]][j-1];
}
int main()
{
    int n;
    ini();
    while(cin>>n)
        cout<<dp[n][4]<<endl;
}
