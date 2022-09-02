/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int traverse(TreeNode* root){
        if(root == nullptr) return 0;
        int left = max(0, traverse(root->left));    //只取正数
        int right = max(0, traverse(root->right));
        res = max(res, left + right + root->val);
        return max(left, right) + root->val;
    }

    int maxPathSum(TreeNode* root) {
        traverse(root);
        return res;
    }

    int res = INT_MIN;
};