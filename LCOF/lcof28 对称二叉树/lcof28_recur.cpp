class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        return root == NULL ? true : child(root->left, root->right);
    }
    bool child(TreeNode* child1,TreeNode* child2){
        if(child1 == NULL && child2 == NULL) return true;
        else if(child1 == NULL|| child2 == NULL || child1->val != child2->val) return false;
        return child(child1->left, child1->right) && child(child1.right, child2.left);
    }
};
