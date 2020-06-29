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
    vector<int> reversePrint(ListNode* head) {
        vector<int> stack;
        vector<int> res;
        for(;head!=NULL;head=head->next){
            stack.push_back(head->val);
        }
        for(int i=stack.size()-1; 0<=i ; --i){
            res.push_back(stack[i]);
        }
        return res;
    }
};