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
    vector<vector<int>> ans;
    vector<vector<int>> BSTSequences(TreeNode* root) {
        if(!root) return {{}};
        queue<TreeNode*> que;
        vector<int> path;
        path.push_back(root->val);
        core(root,que,path);
        return ans;
    }

    void core(TreeNode* root,queue<TreeNode*> que,vector<int> &path){
        if(!root) return;
        if(root->left) que.push(root->left);
        if(root->right) que.push(root->right);
        if(que.empty()){
            ans.push_back(path);
            return;
        }
        int n=que.size();
        while(n--){
            TreeNode* cur=que.front();que.pop();
            path.push_back(cur->val);
            core(cur,que,path);
            que.push(cur);
            path.pop_back();
        }
    }
};