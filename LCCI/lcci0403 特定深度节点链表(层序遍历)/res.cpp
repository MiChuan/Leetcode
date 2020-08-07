/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
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
    vector<ListNode*> listOfDepth(TreeNode* tree) {
        if(tree==nullptr) return vector<ListNode*>();
        vector<ListNode*> v;
        queue<TreeNode*> q;
        q.push(tree);
        while(!q.empty()){
            ListNode *h = new ListNode();//链表头结点
            ListNode *k=h;
            for(int i=q.size(); i>0; i--){//队列大小为当前层节点数
                TreeNode *p = q.front();//队首元素插入链表
                q.pop();
                k->next = new ListNode(p->val);
                k = k->next;//链表遍历指针后移
                if(p->left)q.push(p->left);//左孩子入队
                if(p->right)q.push(p->right);
            }
            v.push_back(h->next);//一层链表加入结果集 
        }
        return v;
    }
};