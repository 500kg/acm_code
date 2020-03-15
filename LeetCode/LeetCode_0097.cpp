class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n = s1.length(), m = s2.length();
        if(n + m != s3.length()) return 0;
        vector<vector<bool>> dp(n + 5, vector<bool>(m + 5, 0));
        dp[0][0] = true;
        for(int i = 1; i <= n; i++)
            dp[i][0] = dp[i - 1][0] && (s1[i - 1] == s3[i - 1]);
        for(int j = 1; j <= m;j++)
            dp[0][j] = dp[0][j - 1] && (s2[j - 1] == s3[j - 1]);
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                if(dp[i - 1][j] && s1[i - 1] == s3[i + j - 1])
                    dp[i][j] = true;
                if(dp[i][j - 1] && s2[j - 1] == s3[i + j - 1])
                    dp[i][j] = true;
            }
        }
        return dp[n][m];
    }
};