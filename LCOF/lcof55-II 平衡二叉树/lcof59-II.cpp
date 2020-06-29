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
    bool isBalanced(TreeNode* root) {
        if(root == NULL) return true;
        return childIsBalanced(root) != -1;
    }
    int childIsBalanced(TreeNode* root){
        if(root == NULL) return 0;
        int leftDepth = childIsBalanced(root->left);
        if(leftDepth == -1) return -1;
        int rightDepth = childIsBalanced(root->right);
        if(rightDepth == -1) return -1;
        return abs(leftDepth - rightDepth) < 2 ? max(leftDepth, rightDepth) + 1 : -1;
    }
};