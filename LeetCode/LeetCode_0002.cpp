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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *root = new ListNode(0);
        ListNode *tmp = root;
        int flag = 0;
        while(l1 != NULL || l2 != NULL || flag){
            int a1 = l1 == NULL ? 0 : l1->val;
            int a2 = l2 == NULL ? 0 : l2->val;
            int ans = a1 + a2 + flag;
            flag = ans/10;
            ans %= 10;
            tmp->next = new ListNode(ans);
            tmp = tmp->next;
            if(l1) l1 = l1->next;
            if(l2) l2 = l2->next;
        }
        return root->next;
    }
};