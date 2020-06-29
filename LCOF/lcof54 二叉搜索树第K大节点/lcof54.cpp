/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int kthLargest(TreeNode* root, int k) {//逆中序遍历
        stack<TreeNode*> nodeStack;
        TreeNode* curNode = root;
        if(root->left == NULL && root->right == NULL && k == 1) return root->val;
        while (curNode != NULL || !nodeStack.empty()){
            while (curNode != NULL){
                nodeStack.push(curNode);
                curNode = curNode->right;
            }
            TreeNode* top = nodeStack.top();
            nodeStack.pop();
            if((--k) == 0) {
                curNode = top;
                break;
            }
            curNode = top->left;
        }
        return curNode->val;
    }
};