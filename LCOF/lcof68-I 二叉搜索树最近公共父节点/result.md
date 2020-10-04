## [LCOF68 - I 二叉搜索树的最近公共祖先](https://leetcode-cn.com/problems/er-cha-sou-suo-shu-de-zui-jin-gong-gong-zu-xian-lcof/)

### 题目

给定一个二叉搜索树, 找到该树中两个指定节点的最近公共祖先。对于有根树 T 的两个结点 p、q，最近公共祖先表示为一个结点 x，满足 x 是 p、q 的祖先且 x 的深度尽可能大（**一个节点也可以是它自己的祖先**）

### 解析

- 祖先的定义：若节点p在节点root的左（右）子树中，或p=root，则称root是p的祖先。
- 最近公共祖先的定义：设节点root为节点p，g的某公共祖先，若其左子节点root.left 和右子节点root.right都不是p，g的公共祖先，则称root是“最近的公共祖先”。
- 根据以上定义，若root是p，g的最近公共祖先，则只可能为以下情况之一：
  1. p和g在root的子树中，且分列root的异侧（即分别在左、右子树中）；
  2. p=root，且g在root的左或右子树中；
  3. g=root，且p在root的左或右子树中；
- 本题给定了两个重要条件：①树为二叉搜索树，②树的所有节点的值都是唯一的。根据以上条件，可方便地判断p，g与root的子树关系，即：
  - 若root.val<p.val，则p在root右子树中；
  - 若root.val>p.val，则p在root左子树中；
  - 若root.val=p.val，则p和root指向同一节点。

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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        while(root!=NULL){
            if(root->val<p->val && root->val<q->val) root=root->right;//两节点在右子树
            else if(root->val>p->val && root->val>q->val) root=root->left;//两节点在左子树
            else break;
        }
        return root;
    }
};
```

