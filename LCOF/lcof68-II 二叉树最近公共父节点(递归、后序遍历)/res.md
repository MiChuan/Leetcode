## [LCOF68 - II 二叉树的最近公共祖先](https://leetcode-cn.com/problems/er-cha-shu-de-zui-jin-gong-gong-zu-xian-lcof/)

### 题目

给定一个二叉树, 找到该树中两个指定节点的最近公共祖先。

### 解析

若 root 是 p, q的 最近公共祖先 ，则只可能为以下情况之一：

1. p 和 q 在 root 的子树中，且分列 root 的 异侧（即分别在左、右子树中）；
2. p = root ，且 q 在 root 的左或右子树中；
3. q = root ，且 p 在 root 的左或右子树中；

![](https://pic.leetcode-cn.com/e48705d412500d43fa81c1d8fdd107bb2d0c7dfa12bdc588cd88f481b4b9f7d8-Picture2.png)

考虑通过递归对二叉树进行后序遍历，当遇到节点 p或 q时返回。从底至顶回溯，当节点 p, q在节点 root的异侧时，节点 root即为最近公共祖先，则向上返回 root。

**递归解析**：

1. 终止条件：

   - 当越过叶节点，则直接返回null；
   - 当root等于p，q，则直接返回root；

2. 递推工作：

   - 开启递归左子节点，返回值记为left；
   - 开启递归右子节点，返回值记为right；

3. 返回值：根据left和right，可展开为四种情况；

   - 当left 和right 同时为空：说明root的左/右子树中都不包含p，q，返回null；

   - 当left和right同时不为空：说明p，q分列在root的异侧（分别在左/右子树），因此root为最近公共祖先，返回root；

   - 当left为空，right 不为空：p，q都不在root的左子树中，直接返回right。具体可分为两种情况：

     - p，q其中一个在root的右子树中，此时right指向p（假设为p）；

     - p，q两节点都在root的右子树中，此时的right 指向最近公共祖先节点；

   - 当left不为空，right为空：与情况3.同理；

[来源](https://leetcode-cn.com/problems/er-cha-shu-de-zui-jin-gong-gong-zu-xian-lcof/solution/mian-shi-ti-68-ii-er-cha-shu-de-zui-jin-gong-gon-7/)

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
    TreeNode* common = NULL;
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        contain(root, p, q);
        return common;
    }

    bool contain(TreeNode* x, TreeNode* p, TreeNode* q){
        if(x == NULL) return false;
        bool left = contain(x->left, p, q);
        bool right = contain(x->right, p, q);
        if((x == p && right) || (x == q && left) || (x == p && left)|| (x == q && right) ||(left && right)) {
            common = x;
            return true;
        }
        return x == p || x == q || left || right;
    }
};
```

