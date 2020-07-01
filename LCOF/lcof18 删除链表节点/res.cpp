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
    ListNode* deleteNode(ListNode* head, int val) {
        if(head == NULL || head->next == NULL && head->val == val) return NULL;
        ListNode* p1 = head;
        if(head->val == val){//首节点是目标节点
            p1 = head->next;
            head->next = NULL;
            return p1;
        }
        while(p1->next->next != NULL){//下一个节点不是尾节点
            if(p1->next->val == val){//下一个节点是目标节点
                ListNode* tmp = p1->next;
                p1->next = p1->next->next;
                tmp->next = NULL;
                return head;
            }
            p1 = p1->next;
        }
        if(p1->next->val == val){//尾节点是目标节点
            p1->next = NULL;
        }
        return head;
    }
};