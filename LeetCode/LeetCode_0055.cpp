class Solution {
public:
    bool canJump(vector<int>& nums) {
        int l = 0, r = 0;
        while(r < nums.size() - 1 && l <= r){
            int pos = -1;
            for(int i = l; i <= r; i++){
                pos = max(pos, i + nums[i]);
            }
            l = r + 1, r = pos;
        }
        return r >= nums.size() - 1;
    }
};