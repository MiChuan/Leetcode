## [LCOF24 反转链表](https://leetcode-cn.com/problems/fan-zhuan-lian-biao-lcof/)

### 题目

定义一个函数，输入一个链表的头节点，反转该链表并输出反转后链表的头节点。

### 解析

四个指针操作

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
```

