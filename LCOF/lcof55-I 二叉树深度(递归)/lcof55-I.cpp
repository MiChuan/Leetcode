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
    int maxDepth(TreeNode* root) {
        if(root == NULL) return 0;
		int depth = 0;
        queue<TreeNode*> nodeQueue;
        nodeQueue.push(root);
        TreeNode* end = root;
        TreeNode* curNode = root;
        while(!nodeQueue.empty()){
            curNode = nodeQueue.front();
            nodeQueue.pop();
            if(curNode->left != NULL){
                nodeQueue.push(curNode->left);
            }
            if(curNode->right != NULL){
                nodeQueue.push(curNode->right);
            }
            if(curNode == end){
                end = nodeQueue.back();
                depth++;
            }
        }
        return depth;
    }
};