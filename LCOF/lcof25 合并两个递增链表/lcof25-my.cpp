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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1 == NULL) return l2;
        if(l2 == NULL) return l1;
        ListNode* head = l1;
        if(l1->next == NULL && l2->next == NULL){//两链表都只有一个节点
            if(l1->val > l2->val){
                head = l2;
                head->next = l1;
            }
            else{
                head->next = l2;
            }
            return head;
        }
        if(l1->val > l2->val){//合并链表首节点最小
            head = l2;
            l2 = l2->next;
            head->next = l1;
            if(l2 == NULL) return head;
        } 
        ListNode* p1 = l1->next;
        ListNode* p2 = l2->next;
        while(p2 != NULL){
            while(!(l2->val >= l1->val && l2->val < p1->val) && p1 != NULL){//查找插入位置
                l1 = p1;
                p1 = p1->next;
            }
            //插入
            l1->next = l2;
            l2->next = p1;
            //下一个插入节点
            l2 = p2;
            p2 = p2->next;
            if(l2->val <= l1->val){
                l1 = l1->next;
            }
            else{
                l1 = p1;
                p1 = p1->next;
            }
        }
        if(l2 != NULL && l1->next == NULL && l2->val >= l1->val) l1->next = l2;
        else if(l2 == NULL);
        else if(l1->val <= l2->val && l2->val < p1->val){
            l1->next = l2;
            l2->next = p1;
        }
        else{
            p1->next = l2;
        }
        return head;
    }
};