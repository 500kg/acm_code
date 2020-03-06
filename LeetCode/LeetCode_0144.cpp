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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        dfs(ans, root);
        return ans;
    }

    void dfs(vector<int> &ans, TreeNode* r){
        if(r == NULL) return;
        ans.push_back(r->val);
        dfs(ans, r->left);
        dfs(ans, r->right);
    }
};