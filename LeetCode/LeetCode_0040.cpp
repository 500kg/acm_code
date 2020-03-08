class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> V;
        vector<vector<int> > ans;
        dfs(ans, candidates, V,0 , -1, target);
        return ans;
    }

    void dfs(vector<vector<int> > &ans,vector<int>& candidates, vector<int> V, int sum, int pos, const int &target){
        if(target == sum){
            ans.push_back(V);
            return;
        }
        
        for(int i = pos + 1; i < candidates.size(); i++){
            if(candidates[i] + sum <= target){
                if(i > pos + 1 && candidates[i] == candidates[i - 1]) continue;
                V.push_back(candidates[i]);
                dfs(ans, candidates, V, sum + candidates[i], i, target);
                V.pop_back();
            }
        }
    }
};