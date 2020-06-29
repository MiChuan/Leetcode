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
    TreeNode* mirrorTree(TreeNode* root) {
        if(root == NULL) return root;
        queue<TreeNode*> nodeQueue;
        nodeQueue.push(root);
        TreeNode* curNode = root;
        TreeNode* temp = NULL;
        while(!nodeQueue.empty()){
            curNode = nodeQueue.front();
            nodeQueue.pop();
            temp = curNode->left;
            curNode->left = curNode->right;
            curNode->right = temp;
            if(curNode->left!=NULL){
                nodeQueue.push(curNode->left);
            }
            if(curNode->right!=NULL){
                nodeQueue.push(curNode->right);
            }
        }
        return root;
    }
};