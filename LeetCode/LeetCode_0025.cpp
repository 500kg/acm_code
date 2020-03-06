/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *root = new ListNode(1);
        ListNode *tmp = root, *h2 = head;
        stack<ListNode*> S;
        while(1){
            int flag = 1;
            for(int i = 0; i < k; i++){
                if(h2 != NULL) {
                    S.push(h2);
                    h2 = h2->next;
                }else flag = 0;
            }
                
            if(flag == 0) {
                tmp->next = head;
                break;
            }
            while(!S.empty()){
                tmp->next = S.top(); S.pop();
                tmp = tmp->next;
            }
            head = h2;
        }
        return root->next;
    }
};