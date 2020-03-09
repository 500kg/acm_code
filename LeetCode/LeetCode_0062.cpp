class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int> > dp(n + 5, vector<int>(m + 5));
         dp[1][0] = 1;
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= m; j++)
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        return dp[n][m];
    }
};