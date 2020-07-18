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
    bool isPalindrome(ListNode* head) {
        if(head==nullptr) return true;
        ListNode* fast=head->next,*slow=head;//快慢指針，快指針在滿指針前一個
        while(fast!=nullptr&&fast->next!=nullptr){
            fast=fast->next->next;
            slow=slow->next;
        }
        ListNode *tp,*p=slow->next,*pre=nullptr;//p是slow后一個，因爲初值処快指針在慢指針下一個，即fast=slow->next。實際上，讓fast=slow,那麽這裏slow應該正好是要反轉部分開頭，但是爲了能斷開兩個節點，必須要讓之前的部分的末尾變爲null，而不是第二部分,所以需要做此處理
        slow->next=nullptr;//讓前部分與後部分斷開
        while(p!=nullptr){//反轉指針部分代碼,最終頭指針為pre
            tp=p->next;
            p->next=pre;
            pre=p;
            p=tp;
        }
        while(head!=nullptr&&pre!=nullptr){
            if(head->val!=pre->val) return false;
            head=head->next;
            pre=pre->next;
        }
        return true;
    }
};