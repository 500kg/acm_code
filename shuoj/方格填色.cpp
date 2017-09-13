#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 1e6 + 5;
const int MOD = 10000007;
int dp[N][9];
void ddp()
{
    int i,flag;
    for(i=0;i<8;i++)
        dp[1][i]=1;
   for(i=2;i<=1e6;i++)
   {
       for(int j=0;j<8;j++)
        {for(int k=0;k<8;k++)
          if (!(j & k) && (j | k))
					dp[i][j] += dp[i - 1][k];
            dp[i][j]%=MOD;
        }
   }

   return ;
}
int main()
{
    int n;
    ddp();
    while(scanf("%d",&n)==1)
    {
        ll res=0;

     for(int i=0;i<8;i++)
            res+=dp[n][i];
            res%=MOD;
        printf("%lld\n",res);

    }
}
