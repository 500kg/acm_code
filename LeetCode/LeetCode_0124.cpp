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
    int maxPathSum(TreeNode* root) {
        int ans = INT_MIN;
        dfs(root, ans);
        return ans;
    }

    int dfs(TreeNode* p, int &ans){
        if(p == NULL) return 0;
        int l = dfs(p->left, ans);
        int r = dfs(p->right, ans);

        ans = max(max(l, 0) + max(r, 0) + p->val, ans);
        return max(0, max(l, r)) + p->val;
    }
};