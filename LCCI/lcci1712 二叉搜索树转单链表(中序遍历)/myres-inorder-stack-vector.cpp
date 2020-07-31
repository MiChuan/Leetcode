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
    TreeNode* convertBiNode(TreeNode* root) {
		if (root == NULL) return root;
        stack<TreeNode*> nodeStack;
        vector<TreeNode*> nodeV;
        TreeNode* curNode = root;
        while (curNode != NULL || !nodeStack.empty()){
            while (curNode != NULL){
                nodeStack.push(curNode);
                curNode = curNode->left;
            }
            TreeNode* top = nodeStack.top();
            nodeStack.pop();
            nodeV.push_back(top);
            curNode = top->right;
        }
        for(int i = 0; i < nodeV.size(); ++i){
            if(i < nodeV.size()-1){
                nodeV[i]->right = nodeV[i+1];
            }
            nodeV[i]->left = NULL;
        }
        return nodeV[0];
    }
};