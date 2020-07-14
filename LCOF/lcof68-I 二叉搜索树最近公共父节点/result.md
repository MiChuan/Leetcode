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