class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> V;
        vector<vector<int> > ans;
        dfs(ans, candidates, V, 0, 0, target);
        return ans;
    }

    void dfs(vector<vector<int> > &ans,vector<int>& candidates, vector<int> V, int sum, int pos, const int &target){
        if(target == sum){
            ans.push_back(V);
        }
        
        for(int i = pos; i < candidates.size(); i++){
            if(candidates[i] + sum <= target){
                V.push_back(candidates[i]);
                dfs(ans, candidates, V, sum + candidates[i], i, target);
                V.pop_back();
            }
        }
    }
};