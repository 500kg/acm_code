#include<bits/stdc++.h>
using namespace std;
char c1[1005],c2[1005];
int dp[1004][1004];
int main()
{
    int T;
    cin>>T;getchar();
    while(T--)
    {
        memset(dp,0,sizeof(dp));
        gets(c1);
        int l1=strlen(c1),l2=l1;
        for(int i=0;i<l1;i++)
            c2[i]=c1[l1-i-1];

        for(int i=0;i<l1;i++)
            for(int j=0;j<l2;j++)
        {
            if(c1[i]==c2[j])
                dp[i+1][j+1]=dp[i][j]+1;
            else
                dp[i+1][j+1]=max(dp[i][j+1],dp[i+1][j]);
        }
        cout<<l1-dp[l1][l2]<<endl;
    }
}
