class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        if(prices.empty()) return 0;
        if(k*2 >= prices.size()){
            int ans = 0;
            for(int i = 1; i < prices.size(); i++)
                if(prices[i] > prices[i - 1]) ans += prices[i] - prices[i - 1];
            return ans;
        }
        vector<vector<vector<int>>> dp(prices.size(), vector<vector<int>>(k + 5, vector<int>(2, -100000000)));
        //dpijk表示第i天买卖j次，k为1表示已买入
        dp[0][0][0] = 0;
        dp[0][0][1] = -prices[0];
        for(int i = 1; i < prices.size(); i++){
            for(int j = 0; j <= k; j++){
                dp[i][j][0] = max(dp[i - 1][j][0], j >= 1 ? dp[i - 1][j - 1][1] + prices[i] : -100000000);
                dp[i][j][1] = max(dp[i - 1][j][1], dp[i - 1][j][0] - prices[i]);
        //       cout<<i<<' '<<j<<' '<<dp[i][j][0]<<' '<<dp[i][j][1]<<endl;
            }
        }
        int ans = 0;
        for(int i = 0; i <= k; i++)
            ans = max(ans, dp[prices.size() - 1][i][0]);
        return ans;
    }
};