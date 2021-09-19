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
    string tree2str(TreeNode* root) 
    {
        //总体逻辑  【访问左子树根值和右子树根值要 递归 去访问】
        //1. 只有1个根节点时，输出：根值（无括号）
        //2. 左节点为空时，输出：根值（无括号） + "()" + '(' + 右子树根值 + ')'
        //3. 右节点为空时，输出：根值（无括号） + '(' + 左子树根值 + ')'
        //4. 左右均不为空，输出：根值（无括号） + '(' + 左子树根值 + ')' + '(' + 右子树根值 + ')'
        //5. 树根节点为nullptr，返回空串

        if(root == nullptr)
            return "";
        if(root->left == nullptr && root->right == nullptr)
        {
            return to_string(root->val);
        }
        else if(root->left == nullptr)
        {
            return to_string(root->val) + '(' + ')' + '(' + tree2str(root->right) + ')';
        }
        else if(root->right == nullptr)
        {
            return to_string(root->val) + '(' + tree2str(root->left) + ')';
        }
        else
        {
            return to_string(root->val) + '(' + tree2str(root->left) + ')' + '(' + tree2str(root->right) + ')';
        }
    }
};