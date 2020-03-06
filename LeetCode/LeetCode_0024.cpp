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
    ListNode* swapPairs(ListNode* head) {
        ListNode *p = head;
        while(1){
            if(p != NULL && p->next != NULL){
                swap(p->val, p->next->val);
                p = p->next->next;
            }else{
                break;
            }
        }
        return head;
    }
};