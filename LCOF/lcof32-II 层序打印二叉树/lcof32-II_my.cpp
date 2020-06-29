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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> order;
        if(root == NULL) return order;
        queue<TreeNode*> nodeQueue;
        TreeNode* curNode = root;
        nodeQueue.push(root);
        vector<int> newvector;
        newvector.push_back(root->val);
        order.push_back(newvector);
        newvector.clear();
        int count = 0;
        int base = 2;
        while(!nodeQueue.empty()){
            curNode = nodeQueue.front();
            if(curNode!=NULL){
                nodeQueue.push(curNode->left);
                nodeQueue.push(curNode->right);
                count = count + 2;
                if(curNode->left!=NULL){
                    newvector.push_back(curNode->left->val);
                }
                if(curNode->right!=NULL){
                    newvector.push_back(curNode->right->val);
                }
                nodeQueue.pop();
            }
            if(count == base){
                order.push_back(newvector);
                count = 0;
                base = newvector.size() * 2;
                newvector.clear();
            }
        }
        return order;
    }
};