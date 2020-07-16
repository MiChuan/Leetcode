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
    int kthToLast(ListNode* head, int k) {
        ListNode* quickP;
        ListNode* slowP;
        int i = k-1;
        for(quickP=head;0<i;--i) quickP=quickP->next;
        for(slowP=head;quickP->next!=NULL;slowP=slowP->next,quickP=quickP->next);
        return slowP->val;
    }
};