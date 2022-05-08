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
    //简单遍历, 遍历所有结点，统计个数 O(N)
    // int countNodes(TreeNode* root) 
    // {
    //     if(root == nullptr)
    //         return 0;
        
    //     int leftNodes = countNodes(root->left);
    //     int rightNodes = countNodes(root->right);

    //     return 1 + leftNodes + rightNodes;
    // }

    //将完全二叉树拆分为多个"满二叉树"  O(logN * logN)
    //分别求: 左子树和右子树的高度; 
    //判断高度是否相同(left->left->left, right->right->right; 只需要判断最左和最右)，
    //如果相同，则说明是满二叉树;
    //如果不同，递归继续拆分;
    int countNodes(TreeNode* root) 
    {
        if(root == nullptr)
            return 0;
        
        int leftHeight = 0;
        int rightHeight = 0;
        TreeNode* left = root->left;
        while(left)
        {
            left = left->left;
            ++leftHeight;
        }

        TreeNode* right = root->right;
        while(right)
        {
            right = right->right;
            ++rightHeight;
        }

        if(leftHeight == rightHeight){  //如果是满二叉树，直接利用公式计算个数
            return (2 << leftHeight) - 1; //注意是2 << n，如果只有1层，则是2 << 0 - 1 = 1个; 2层就是3个
        }
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};