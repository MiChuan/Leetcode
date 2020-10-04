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
        ListNode* curNext = head->next;//下一个需要翻转的节点
        while(curNext != NULL){//2个及以上节点
            ListNode* tmp = curNext->next;//保存翻转节点后继节点
            curNext->next = curHead;//翻转的节点放到头部
            curHead = curNext;//翻转后的节点为当前头部
            curNext = tmp;//下一个节点
        }
        curTail->next = nullptr;
        return curHead;
    }
};