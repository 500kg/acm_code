class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;
        int ans = 0, l = 0, r = 0;
        while(r < n - 1){
            int t = 0;
            for(int i = l; i <= r; i++)
                t = max(t, i + nums[i]);
            l = r + 1;
            r = t;
            ans++;
        }
        return ans;
    }
};