class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> ret(k);
        dfs(1, n, 0, k, ret, ans);
        return ans;
    }

    void dfs(int num, int tot, int cnt, int totcnt, vector<int> &ret, vector<vector<int>> &ans){
        if(totcnt == cnt){
            ans.push_back(ret);
            return;
        }
        for(int i = num; i <= tot; i++){
            ret[cnt] = i;
            dfs(i + 1, tot, cnt + 1, totcnt, ret, ans);
        }
    }
};