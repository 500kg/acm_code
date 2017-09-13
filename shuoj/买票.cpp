#include<bits/stdc++.h>
using namespace std;

#define maxn 2050

int n;
int k;
int dp[maxn];
int one[maxn];
int two[maxn];

int main()
{
    scanf("%d", &n);
    while( n-- )
    {
        memset(dp, 0, sizeof(dp));
        memset(one, 0, sizeof(one));
        memset(two, 0, sizeof(two));
        scanf("%d", &k);
        for(int i=1; i<=k; i++)
            scanf("%d",&one[i]);
        for(int i=2; i<=k; i++)
            scanf("%d",&two[i]);
        dp[0]=0;dp[1]=one[1];
        for(int i=2; i<=k; i++)
            dp[i] = min(dp[i-1]+one[i],dp[i-2]+two[i]);


        int h = dp[k] / 3600 + 8;
        int m = dp[k] / 60 % 60;
        int s = dp[k] % 60;

        printf("%02d:%02d:%02d am\n", h, m, s);
    }

    return 0;
}
