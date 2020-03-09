class Solution {
public:
    int maxProfit(vector<int>& p) {
        if(p.empty()) return 0;
        int mini = p[0], ans = 0;
        for(int i = 0; i < p.size(); i++){
            ans = max(ans, p[i] - mini);
            mini = min(p[i], mini);
        }
        return ans;
    }
};