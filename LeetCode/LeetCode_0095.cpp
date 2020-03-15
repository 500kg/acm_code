/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        if(n == 0) return vector<TreeNode*>();
        return dfs(1, n);
    }
    vector<TreeNode*> dfs(int l, int r){
        vector<TreeNode*> ans;
        if(l > r){
            ans.push_back(NULL);
            return ans;
        }
        for(int i = l; i <= r; i++){
            vector<TreeNode*> L = dfs(l, i - 1);
            vector<TreeNode*> R = dfs(i + 1, r);
            for(auto &ll: L)
                for(auto &rr: R){
                    TreeNode *tmp = new TreeNode(i);
                    tmp->left = ll;
                    tmp->right = rr;
                    ans.push_back(tmp);
                }
        }
        return ans;
    }
};