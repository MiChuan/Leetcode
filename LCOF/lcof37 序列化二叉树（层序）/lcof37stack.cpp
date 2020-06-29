/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root == NULL) return "[null]";
        string tree = "[";
        if(root->left == NULL && root->right == NULL){//只有一个节点
            tree.append(to_string(root->val));
            tree.append("]");
            return tree;
        }
        TreeNode* stack[1000],curNode;
        int top = 0;
        //stack[++top] = root;
        curNode = root;
        tree.append(to_string(root->val));//根节点序列化
        while(true){
           if(curNode->left == NULL && curNode->right == NULL){//当前节点为叶子节点
               tree.append(",null");
               tree.append(",null");
               if(top!=0){
                   curNode = stack[top--];//退回父节点的右节点 
               }
               else break;
           }
           else{
               if(curNode->left != NULL){//当前节点左节点序列化
                   tree.append(",");
                   tree.append(to_string(curNode->left->val));
                   if(curNode->right != NULL){//当前节点右节点序列化
                       tree.append(",");
                       tree.append(to_string(curNode->right->val));
                       stack[++top] = curNode->right;//右节点压栈
                   }
                   else{//当前节点右节点为空
                       tree.append(",null");
                   }
                   curNode = curNode->left;//向左节点深入
               }
               else{//当前节点左节点为空
                   tree.append(",null");
                   tree.append(",");
                   tree.append(to_string(curNode->right->val));
                   curNode = curNode->right;//向右节点深入
               }
           } 
        }
        tree.append("]");
        return tree;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));