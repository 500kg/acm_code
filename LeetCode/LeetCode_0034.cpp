class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.empty() || nums[0] > target || nums[nums.size() - 1] < target || nums[lower_bound(nums.begin(), nums.end(), target) - nums.begin()] != target) return vector<int>{-1, -1};
        int pos1 = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
        int pos2 = upper_bound(nums.begin(), nums.end(), target) - nums.begin() - 1;
        return vector<int>{pos1, pos2};
    }
};