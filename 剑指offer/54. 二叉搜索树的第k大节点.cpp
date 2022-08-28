class Solution {
public:
    void dfs(TreeNode* root, int k){
        if(root == nullptr)    return;
        dfs(root->right, k);
        ++index;
        if(index == k){
            res = root->val;
            return;
        }
        dfs(root->left, k);
    }

    int kthLargest(TreeNode* root, int k) {
        dfs(root, k);
        return res;
    }
    int res = 0;
    int index = 0;
};