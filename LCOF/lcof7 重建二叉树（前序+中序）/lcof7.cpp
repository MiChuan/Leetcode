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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.size() == 0) return NULL;
        TreeNode* root = new TreeNode(preorder[0]);
        TreeNode* stack[5001];
        TreeNode* nodeNow = NULL;
        TreeNode* nodeNext = NULL;
        nodeNow = root;
        int top = 0;
        stack[++top]= nodeNow;
        int pr,i;
        vector<int>::iterator itInCur,itInNext,itInStack;
        for(pr=0;pr<preorder.size()-1; pr++){
            nodeNext = new TreeNode(preorder[pr+1]);
            itInCur = find(inorder.begin(), inorder.end(), preorder[pr]);
            itInNext = find(inorder.begin(), inorder.end(), preorder[pr+1]);
            if(itInNext<itInCur){
                nodeNow->left = nodeNext;
                stack[++top]= nodeNext;
                nodeNow = nodeNext;
            }
            else{
                if(top!=0){
                    i = top;
                    do{
                        itInStack = find(inorder.begin(), inorder.end(), stack[i]->val);
                        if(itInStack<itInNext) i--;
                    }while(i!=0 && itInStack<itInNext);
                    top = i + 1;
                    stack[top]->right = nodeNext;
                    top--;
                    stack[++top]= nodeNext;
                    nodeNow = nodeNext;
                }
            }
        }
        return root;
    }
};