## [LCOF22 链表中倒数第k个节点](https://leetcode-cn.com/problems/lian-biao-zhong-dao-shu-di-kge-jie-dian-lcof/)

### 题目

输入一个链表，输出该链表中倒数第k个节点，从1开始计数。

### 解析

快慢指针，快指针先走k-1步，再一起走。

### 代码

```C++
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
    ListNode* getKthFromEnd(ListNode* head, int k) {
        if(head == NULL) return head;
        ListNode* quickP;
        ListNode* slowP;
        int i = k-1;
        for(quickP=head;0<i;--i) quickP=quickP->next;
        for(slowP=head;quickP->next!=NULL;slowP=slowP->next,quickP=quickP->next);
        return slowP;
    }
};
```

