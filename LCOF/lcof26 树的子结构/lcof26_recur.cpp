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
    bool isSubStructure(TreeNode* A, TreeNode* B) {
        return (A != NULL && B != NULL) && (isEqual(A,B) || isSubStructure(A->left,B) || isSubStructure(A->right,B));
    }
    bool isEqual(TreeNode* A, TreeNode* B){
        if(B == NULL) return true;
        if(A == NULL || A->val != B->val) return false;
        return (isEqual(A->left,B->left) && isEqual(A->right,B->right));
    }
};