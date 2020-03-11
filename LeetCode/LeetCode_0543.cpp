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
    int diameterOfBinaryTree(TreeNode* root) {
        if(root == NULL) return 0;
        int ans = 0;
        dfs(root, ans);
        return ans;
    }

    int dfs(TreeNode *p, int &ans){
        if(p == NULL) return 0;
        int l = dfs(p->left, ans);
        int r = dfs(p->right, ans);
        ans = max(ans, l + r);
        return max(l, r) + 1;
    }
};