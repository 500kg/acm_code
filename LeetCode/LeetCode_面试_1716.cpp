class Solution {
public:
    int massage(vector<int>& nums) {
        vector<int> dp(nums.size() + 5);
        if(nums.empty()) return 0;
        if(nums.size() == 1) return nums[0];
        if(nums.size() == 2) return max(nums[0], nums[1]);
     //   cout << nums.size()<<endl;
        dp[0] = nums[0], dp[1] = max(dp[0], nums[1]);
        for(int i = 2; i < nums.size(); i++)
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
        return dp[nums.size() - 1];
    }
};