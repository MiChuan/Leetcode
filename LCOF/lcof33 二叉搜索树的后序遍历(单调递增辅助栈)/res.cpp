class Solution {
public:
    bool verifyPostorder(vector<int>& postorder) {
    	// 单调栈使用，单调递增的单调栈
    	stack<int> nstack;
        // 表示上一个根节点的元素，这里可以把postorder的最后一个元素root看成无穷大节点的左孩子
        int pervElem = 114511;
        // 逆向遍历，就是翻转的先序遍历,root->right->left
        for (int i = postorder.size()- 1;i>=0;i--){
            // 左子树元素必须要小于递增栈被peek访问的元素，否则就不是二叉搜索树
            if (postorder[i] > pervElem){
                return false;
            }
            while (!nstack.empty() && postorder[i] < nstack.top()){
                // 数组元素小于单调栈的元素了，表示往左子树走了，记录下上个根节点
                // 找到这个左子树对应的根节点，之前右子树全部弹出，不再记录，因为不可能在往根节点的右子树走了
                pervElem = nstack.top();
                nstack.pop();
            }
            // 这个新元素入栈
            nstack.push(postorder[i]);
        }
        return true;
    }
};