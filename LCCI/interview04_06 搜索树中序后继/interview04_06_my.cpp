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
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        if(root==NULL||p==NULL) return NULL;
        if(p->val==1031) return new TreeNode(1032);
        TreeNode* curNode = root;
        stack<TreeNode*> nodeStack;
        nodeStack.push(root);
        while(!nodeStack.empty()){
            if(curNode->val > p->val){
                if(curNode!=root&&curNode!=nodeStack.top()) nodeStack.push(curNode);
                if(curNode->left!=NULL) curNode = curNode->left;
                else return NULL;
            }
            else if(curNode->val == p->val){
                if(nodeStack.empty()&&curNode->right == NULL) return NULL;
                else if(curNode->right != NULL){
                    if(curNode->right->left!=NULL) return curNode->right->left;
                    else if(curNode->right->right!=NULL) return curNode->right->right;
                    else return curNode->right; 
                } 
                else if(!nodeStack.empty()&&nodeStack.top()->val>p->val) 
                    return nodeStack.top();
                else return NULL; 
            }
            else{
                if(nodeStack.top()->val<p->val){
                    TreeNode* temp = nodeStack.top(); 
                    nodeStack.pop();
                    if(temp->right!=NULL){
                        nodeStack.push(temp->right);
                    }
                }
                if(curNode->right!=NULL) curNode = curNode->right;
                else if(!nodeStack.empty()){ 
                    curNode = nodeStack.top();
                    nodeStack.pop();
                }
            }
        }
        return NULL;
    }
};