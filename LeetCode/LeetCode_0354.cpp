class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& en) {
        vector<pair<int, int> > V;
        if(en.size() == 0) return 0;
        for(auto &v : en)
            V.push_back(make_pair(v[0], -v[1]));
        sort(V.begin(), V.end());
        vector<int> dp(V.size() + 100, 0x3f3f3f3f);
        for(int i = 0; i < V.size(); i++){
            int t = -V[i].second;
            t = lower_bound(dp.begin(), dp.end(), t) - dp.begin();
            dp[t] = -V[i].second;
        }
        return lower_bound(dp.begin(), dp.end(), 0x3f3f3f3f) - dp.begin();
    }
};