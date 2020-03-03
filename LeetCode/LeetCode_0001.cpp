class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> M;
        for(int i = 0; i < nums.size(); i++){
            if(M[target - nums[i]]){
                vector<int> ans{M[target - nums[i]] - 1, i};
                return ans;
            }
            M[nums[i]] = i + 1;
        }
        return nums;
    }
};