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
    vector<int> levelOrder(TreeNode* root) {
        vector<int> nodes;
        if(root!=NULL){
            TreeNode* curNode = root;
            queue<TreeNode*> nodeQ;
            nodes.push_back(curNode->val);
            nodeQ.push(curNode);
            while(curNode!=NULL&&!nodeQ.empty()){
                curNode=nodeQ.front();
                nodeQ.pop();
                if(curNode->left!=NULL){
                    nodeQ.push(curNode->left);
                    nodes.push_back(curNode->left->val);
                }
                if(curNode->right!=NULL){
                    nodeQ.push(curNode->right);
                    nodes.push_back(curNode->right->val);
                }
            }
        }
        return nodes;
    }
};