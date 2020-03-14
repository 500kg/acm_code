class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> v(nums.size() + 5, 0x3f3f3f3f);
        for(auto &s: nums){
            int pos = lower_bound(v.begin(), v.end(), s) - v.begin();
            v[pos] = s;
        }
        return lower_bound(v.begin(), v.end(), 0x3f3f3f3f) - v.begin();
    }
};