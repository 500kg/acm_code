class Solution {
public:
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(),1);
        nums.push_back(1);
        int n = nums.size();
        if(n == 0) return 0;
        if(n == 1) return nums[0];
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for(int t = 2; t < n; t++)
            for(int i = 0, j = i + t; j < n; i++, j++)
                for(int k = i + 1; k < j; k++)
                    dp[i][j] = max(dp[i][j], dp[i][k] + dp[k][j] + nums[i]*nums[j]*nums[k]);
        return dp[0][n - 1];
    }
};