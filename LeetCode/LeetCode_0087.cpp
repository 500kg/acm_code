class Solution {
public:
    bool isScramble(string s1, string s2) {
        int n = s1.length(), m = s2.length();
        if(n != m) return false;
        //dp[i][j][k] 表示s[i:i+k]是否与s[j:j+k]匹配
        vector<vector<vector<bool>>> dp(n, vector<vector<bool>>(n, vector<bool>(n + 5, 0)));
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                dp[i][j][1] = s1[i] == s2[j];
        
        for(int len = 2; len <= n; len++)
            for(int i = 0; i + len <= n; i++)
                for(int j = 0; j + len <= n; j++)
                    for(int k = 1; k < len; k++){
                        if(dp[i][j][k] && dp[i + k][j + k][len - k])
                            dp[i][j][len] = true;
                        if(dp[i][j + k][len - k] && dp[i + len - k][j][k])
                            dp[i][j][len] = true;
                    }
        return dp[0][0][n];
                
    }
};