class Solution {
public:
    int minPathSum(vector<vector<int>>& G) {
        if(G.empty() || G[0].empty()) return 0;
        int n = G.size(), m = G[0].size();
        vector<vector<int> > dp(n + 5, vector<int>(m + 5, 0));
        for(int i = 1; i <= n; i++) dp[i][1] = G[i - 1][0] + dp[i - 1][1];
        for(int i = 1; i <= m; i++) dp[1][i] = G[0][i - 1] + dp[1][i - 1];
        for(int i = 2; i <= n; i++)
            for(int j = 2; j <= m; j++)
                dp[i][j] = min(dp[i - 1][j], dp[i][j -1]) + G[i - 1][j - 1];

        return dp[n][m];
    }
};