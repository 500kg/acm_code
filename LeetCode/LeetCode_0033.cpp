class Solution {
public:
    int search(vector<int>& nums, int tar) {
        if(nums.size() == 0) return -1;
        int l = 0, r = nums.size() - 1, ans = 0, mid;
        while(l <= r){
            mid = l + r >> 1;
            if(nums[mid] < nums[0])
                r = mid - 1;
            else 
                l = mid + 1, ans = mid;
        }
        if(tar >= nums[0])
            r = ans, l = 0;
        else
            l = ans + 1, r = nums.size() - 1;
        while(l <= r){
            mid = l + r >> 1;
            if(nums[mid] >= tar)
                r = mid - 1, ans = mid;
            else
                l = mid + 1;
        }
        return nums[ans] == tar ? ans : -1;
    }
};