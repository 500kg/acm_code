/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() {}

    Node(int _val, Node* _left, Node* _right, Node* _next) {
        val = _val;
        left = _left;
        right = _right;
        next = _next;
    }
};
*/
class Solution {
public:
    struct node
    {
        Node *no;
        int dep;
        node(Node *_no, int _dep)
        {
            no = _no, dep = _dep;
        }
    };
    void bfs(Node* root)
    {
        node tmp(root, 0);
        queue<node>Q;
        Q.push(tmp);
        while(!Q.empty())
        {
            
            tmp = Q.front();Q.pop();//cout<<tmp.no->val<<endl;
            if(Q.empty() || Q.front().dep != tmp.dep)tmp.no->next = NULL;
            else tmp.no->next = Q.front().no;
            if(tmp.no->left != NULL)Q.push(node(tmp.no->left, tmp.dep + 1));
            if(tmp.no->right != NULL)Q.push(node(tmp.no->right, tmp.dep + 1));
        }
    }
    Node* connect(Node* root) {
        if(root != NULL)
           bfs(root);
        return root;
    }
};