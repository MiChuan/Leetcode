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
        if(root != NULL){
        	queue<TreeNode*> nodeQueue;
        	nodeQueue.push(root);
        	vector<int> newvector;
        	while(!nodeQueue.empty()){
            	for(int i=nodeQueue.size(); i>0; i--){
                	TreeNode* curNode = nodeQueue.front();
                	nodeQueue.pop();
                	newvector.push_back(curNode->val);
                	if(curNode->left != NULL){
                    	nodeQueue.push(curNode->left);
                	}
                	if(curNode->right != NULL){
                    	nodeQueue.push(curNode->right);
                	}
            	}
           		order.push_back(newvector);
           		newvector.clear();
           	}
        }
        return order;
    }
};