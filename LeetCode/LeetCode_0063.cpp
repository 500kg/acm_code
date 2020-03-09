class Solution {
public:
    long long uniquePathsWithObstacles(vector<vector<int>>& G) {
        if(G.empty() || G[0].empty()) return 0;
        int n = G.size(), m = G[0].size();
        vector<vector<long long> > dp(n, vector<long long>(m, 0));
        for(int i = 0; i < m; i++)
            if(G[0][i] == 1) break;
            else dp[0][i] = 1;
        for(int i = 0; i < n; i++)
            if(G[i][0] == 1) break;
            else dp[i][0] = 1;
        for(int i = 1; i < n; i++)
            for(int j = 1; j < m; j++)
                if(G[i][j] == 0)
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        return dp[n - 1][m - 1];
    }
};