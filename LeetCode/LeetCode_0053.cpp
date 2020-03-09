class Solution {
public:
    int maxSubArray(vector<int>& a) {
        int ans = a[0], ret = a[0];
        for(int i = 1; i < a.size(); i++){
            if(ret < 0) ret = a[i];
            else ret += a[i];
            ans = max(ans, ret);
        }
        return ans;
    }
};