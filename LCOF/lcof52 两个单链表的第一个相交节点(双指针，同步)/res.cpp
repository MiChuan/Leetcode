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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA != NULL && headB != NULL){
            int countA = 1, countB = 1;
            ListNode* curA = headA;
            ListNode* curB = headB;
            while(curA != NULL){
                curA = curA->next;
                ++countA;
            }
            while(curB != NULL){
                curB = curB->next;
                ++countB;
            }
            curA = headA;
            curB = headB;
            if(countA > countB){
                for(int i = 0; i < countA - countB; ++i) curA = curA->next;
            }
            if(countA < countB){
                for(int i = 0; i < countB - countA; ++i) curB = curB->next;
            }
            while(curA != NULL && curB != NULL){
                if(curA == curB) return curA;
                else{
                    curA = curA->next;
                    curB = curB->next;
                }
            }
        }
        return NULL;
    }
};