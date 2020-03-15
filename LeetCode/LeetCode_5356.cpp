class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& M) {
        vector<int>ans;
        int n = M.size(), m = M[0].size();
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                int t = M[i][j];
                bool flag = true;
                for(int k = 0; k < n; k++) if(t < M[k][j]) flag = false;
                for(int k = 0; k < m; k++) if(t > M[i][k]) flag = false;
                if(flag) ans.push_back(t);
            }
        }
        return ans;
    }
};