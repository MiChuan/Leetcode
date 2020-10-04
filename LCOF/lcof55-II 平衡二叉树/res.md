## [LCOF55 - II 平衡二叉树](https://leetcode-cn.com/problems/ping-heng-er-cha-shu-lcof/)

### 题目

输入一棵二叉树的根节点，判断该树是不是平衡二叉树。如果某二叉树中任意节点的左右子树的深度相差不超过1，那么它就是一棵平衡二叉树。

### 解析

- 递归求左右子树深度，并判断左右子树是否平衡
- 计算左右子树深度差，判断当前节点树是否平衡

### 代码

```C++
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
    bool isBalanced(TreeNode* root) {
        if(root == NULL) return true;
        return childIsBalanced(root) != -1;
    }
    int childIsBalanced(TreeNode* root){
        if(root == NULL) return 0;
        int leftDepth = childIsBalanced(root->left);
        if(leftDepth == -1) return -1;
        int rightDepth = childIsBalanced(root->right);
        if(rightDepth == -1) return -1;
        return abs(leftDepth - rightDepth) < 2 ? max(leftDepth, rightDepth) + 1 : -1;
    }
};
```

