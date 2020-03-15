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
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> val;
        dfs(root, val);
        return fak(val, 0, val.size() - 1);
    }
    
    void dfs(TreeNode* p, vector<int> &val){
        if(p == NULL) return;
        
        dfs(p->left, val);
        val.push_back(p->val);
        dfs(p->right, val);
    }
    
    TreeNode* fak(vector<int> &val, int l, int r){
        if(l > r) return NULL;
        int mid = l + r >> 1;
        TreeNode *tmp = new TreeNode(val[mid]);
        tmp->left = fak(val, l, mid - 1);
        tmp->right = fak(val, mid + 1, r);
        return tmp;
    }
};