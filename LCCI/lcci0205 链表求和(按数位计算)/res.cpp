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
        ListNode* sum=l1;
        while(l1 && l2){
            if((l1->val+l2->val)>=10){//产生进位
                l1->val = (l1->val+l2->val)%10;
                if(!l1->next) l1->next = new ListNode(0);    
                ++l1->next->val;
            } else l1->val = l1->val+l2->val;
            if(!l1->next&& !l2->next) break;//同时到达尾部，计算完毕
            if(!l1->next) l1->next = new ListNode(0);//扩展l1
            if(!l2->next) l2->next = new ListNode(0);//扩展l2
            l1=l1->next;
            l2=l2->next;
        }
        return sum;
    }
};