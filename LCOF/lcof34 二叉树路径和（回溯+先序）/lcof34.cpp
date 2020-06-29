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
    vector<vector<int>> route;
    vector<int> path;
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        findRoute(root,sum);
        return route;
    }
    void findRoute(TreeNode* root, int sum){
        if(root == NULL) return;
        path.push_back(root->val);
        sum -= root->val;
        if(sum==0 && root->left==NULL && root->right==NULL) route.push_back(path);
        findRoute(root->left,sum);
        findRoute(root->right,sum);
        path.pop_back();
    }
};