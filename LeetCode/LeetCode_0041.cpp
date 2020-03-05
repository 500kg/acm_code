class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 1;
        for(int i = 0; i < nums.size(); i++)
            if(nums[i] <= 0 || nums[i] > n) nums[i] = -1;
        for(int i = 0, t; i < nums.size(); i++){
            if(nums[i] < 0) continue;
            while(t = nums[i]){
                if(t < 0 || nums[t - 1] == -2) break;
                swap(nums[i], nums[t - 1]);
                nums[t - 1] = -2;
            }
        }
        int ans = n + 1;
        for(int i = 0; i < n; i++){
  //          cout << nums[i] << endl;
            if(nums[i] != -2)
                return i + 1;
        }
            
        return ans;
    }
};