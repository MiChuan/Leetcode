class Solution {
public:
    int res=0;
    int pathSum(TreeNode* root, int sum) {
        if(!root)return 0;
        dfs(root,sum);
        pathSum(root->left,sum);
        pathSum(root->right,sum);
        return res;
    }

    void dfs(TreeNode* root,int sum)
    {
        if(!root)return;
        if(root->val==sum) res++;
        dfs(root->left,sum-root->val);
        dfs(root->right,sum-root->val);
    }
};