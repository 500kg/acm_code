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
    bool isBalanced(TreeNode* root) {
        bool ans = true;
        dfs(root, ans);
        return ans;
    }

    int dfs(TreeNode *t, bool &ans){
        if(t == NULL) return 0;
        int l = dfs(t->left, ans);
        int r = dfs(t->right, ans);
        if(abs(l - r) > 1) ans = false;
        return max(l, r) + 1;
    }
};