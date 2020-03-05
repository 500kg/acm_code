class Solution {
public:
    int trap(vector<int>& h) {
        if(h.empty()) return 0;
        vector<int> PreMax(h.size(), 0);
        vector<int> LasMax(h.size(), 0);
        int n = h.size();
        PreMax[0] = h[0];
        for(int i = 1; i < h.size(); i++) PreMax[i] = max(PreMax[i - 1], h[i]);
        LasMax[n - 1] = h[n - 1];
        for(int i = n - 2; i >= 0; i--) LasMax[i] = max(LasMax[i + 1], h[i]);
        int ans = 0;
        for(int i = 0; i < n; i++)
            ans += min(PreMax[i], LasMax[i]) - h[i];
        return ans;
    }
};