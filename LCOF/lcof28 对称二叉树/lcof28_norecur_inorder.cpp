class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(root == NULL) return true;
        std::vector<TreeNode*> nodeOrder;
        std::stack<TreeNode*> nodeStack;
        TreeNode* curNode = root;
        while(curNode != NULL || !nodeStack.empty()){
        	while(curNode!=NULL){
        		nodeStack.push(curNode);
        		curNode = curNode->left;
        	}
        	nodeOrder.push_back(NULL);
        	nodeOrder.push_back(nodeStack.top());
        	curNode = (nodeStack.top())->right;
        	nodeStack.pop();
        }
        int begin,end;
        for(begin = 0, end = nodeOrder.size()-1; begin<=end ; begin++,end--){
        	if(nodeOrder[begin] == NULL && nodeOrder[end] == NULL) continue;
        	if(nodeOrder[begin] == NULL && nodeOrder[end] != NULL || 
        		nodeOrder[begin] != NULL && nodeOrder[end] == NULL) return false;
        	if(nodeOrder[begin]->val != nodeOrder[end]->val) return false;
        }
        return true;
    }
};
