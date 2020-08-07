class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        if(head==nullptr){
            return nullptr;
        }

        //链表存在的情况
        ListNode* cur=head;
        ListNode* big_head=new ListNode(0);
        ListNode* small_head=new ListNode(0);
        ListNode* big=big_head;
        ListNode* small=small_head;
        while(cur){
            if(cur->val>=x){
                big->next=cur;
                big=big->next;
                cur=cur->next;
                big->next=nullptr;
            }else {
                small->next=cur;
                small=small->next;
                cur=cur->next;
                small->next=nullptr;
            }  
        }
        small->next=big_head->next;//伪结点的处理
        return small_head->next;//伪结点的处理
    }
};