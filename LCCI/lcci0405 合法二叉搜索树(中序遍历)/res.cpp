/* Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> res;
    void pre(TreeNode* root){
        if(root->left){
            pre(root->left);
        }
        res.push_back(root->val);
        if(root->right){
            pre(root->right);
        }
    }

    bool isValidBST(TreeNode* root) {
        
        if(root==NULL){
            return true;
        }
        pre(root);

        for(int i=1;i<res.size();i++){
            if(res[i]<=res[i-1]){
                return false;
            }
        }

        return true;

    }
};