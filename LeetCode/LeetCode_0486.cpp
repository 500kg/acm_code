class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        return fak(nums, 0, nums.size() - 1) >= 0;
    }

    long long fak(vector<int>&num, int l, int r){
        if(l == r) return num[l];
        return max(num[r] - fak(num, l, r - 1), num[l] - fak(num, l + 1, r));
    }
};