/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
struct cmp
{
	bool operator()(const ListNode *a,const ListNode *b)
	{
		return a->val > b->val;
	}	
};
class Solution {
public:
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty()) return NULL;
        ListNode *root = new ListNode(0);
        ListNode *tmp = root;

        priority_queue<ListNode*, vector<ListNode*>, cmp> Q;
        for(auto &v : lists){
            if(v!=NULL) Q.push(v);
        }
            
        if(Q.empty()) return NULL;
        while(!Q.empty()){
            auto t = Q.top(); Q.pop();
    //        cout<<t->val<<endl;
            if(t->next != NULL) Q.push(t->next);
            if(tmp != NULL) tmp->next = new ListNode(t->val);
            if(tmp != NULL) tmp = tmp->next;
        }
        if(root != NULL) return root->next;
        return NULL;
    }
};