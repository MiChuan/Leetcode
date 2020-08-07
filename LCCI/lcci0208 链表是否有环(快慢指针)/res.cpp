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
    ListNode *detectCycle(ListNode *head) {
        if(head == NULL || head->next == NULL) return NULL;
        ListNode* low = head, *fast = head;
        while(fast && fast->next){
            low = low->next;
            fast = fast->next->next;
            if(fast == low)
                break;
        }
        if(fast != low) return NULL;
        fast = head;
        while(fast != low){
            fast = fast->next;
            low = low->next;
        }
        return fast;
    }
}; 