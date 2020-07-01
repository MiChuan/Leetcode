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
    ListNode* reverseList(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;//0或1个节点
        ListNode* curHead = head;
        ListNode* curTail = head;
        ListNode* curNext = head->next;
        while(curNext != NULL){//2个及以上节点
            ListNode* tmp = curNext->next;
            curNext->next = curHead;
            curTail->next = tmp;
            curHead = curNext;
            curNext = tmp;
        }
        return curHead;
    }
};