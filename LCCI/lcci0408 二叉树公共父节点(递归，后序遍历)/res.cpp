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
    TreeNode* common = NULL;
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        contain(root, p, q);
        return common;
    }

    bool contain(TreeNode* x, TreeNode* p, TreeNode* q){
        if(x == NULL) return false;
        bool left = contain(x->left, p, q);
        bool right = contain(x->right, p, q);
        if((x == p && right) || (x == q && left) || (x == p && left)|| (x == q && right) ||(left && right)) {
            common = x;
            return true;
        }
        return x == p || x == q || left || right;
    }
};