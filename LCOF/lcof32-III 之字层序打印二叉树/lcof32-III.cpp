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
        deque<TreeNode*> nodeQueue;
        nodeQueue.push_back(root);
        TreeNode* end = root;
        vector<int> newvector;
        int direct = 0;
        TreeNode* curNode = root;
        while(!nodeQueue.empty()){
            if(direct == 0){//right
                curNode = nodeQueue.front();                  
                nodeQueue.pop_front();
                newvector.push_back(curNode->val);
                if(curNode->left != NULL){
                    nodeQueue.push_back(curNode->left);
                }
                if(curNode->right != NULL){
                    nodeQueue.push_back(curNode->right);
                }
                if(curNode == end){
                    end = nodeQueue.front();
                    order.push_back(newvector);
                    newvector.clear();
                    direct = 1;
                }
            }
            else{//left
                curNode = nodeQueue.back();
                nodeQueue.pop_back();
                newvector.push_back(curNode->val);
                if(curNode->right != NULL){
                    nodeQueue.push_front(curNode->right);
                }
                if(curNode->left != NULL){
                    nodeQueue.push_front(curNode->left);
                }
                if(curNode == end){
                    end = nodeQueue.back();
                    order.push_back(newvector);
                    newvector.clear();
                    direct = 0;
                }
            }

        }
        return order;
    }
};