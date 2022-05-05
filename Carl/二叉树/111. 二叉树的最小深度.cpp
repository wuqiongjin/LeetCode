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
    // //二叉树的最小深度是指: 根结点到叶子结点的深度 (你不是叶子结点就不能算最小深度)
    // int minDepth(TreeNode* root) 
    // {
    //     if(root == nullptr)
    //         return 0;
    //     int leftDepth = minDepth(root->left);   //左
    //     int rightDepth = minDepth(root->right); //右

    //                                             //中
    //     //右边还有分支，说明当前结点"不是叶子结点"，此时返回右边的深度(不能返回左边的)
    //     if(root->left == nullptr && root->right != nullptr){
    //         return 1 + rightDepth;
    //     }
    //     else if(root->right == nullptr && root->left != nullptr){
    //         return 1 + leftDepth;
    //     }

    //     //左右都不为空，此时返回左右深度最小的
    //     return 1 + min(leftDepth, rightDepth);
    // }

    // 简洁版
    // int minDepth(TreeNode* root) 
    // {
    //     if(root == nullptr)
    //         return 0;
        
    //     if(root->left == nullptr && root->right == nullptr)
    //         return 1;
    //     else if(root->left && root->right)
    //         return 1 + min(minDepth(root->left), minDepth(root->right));
    //     else if(root->left)
    //         return 1 + minDepth(root->left);
    //     else
    //         return 1 + minDepth(root->right);
    // }


    // 迭代法(层序遍历，依然是找叶子结点)
    int minDepth(TreeNode* root)
    {
        if(root == nullptr) return 0;
        queue<TreeNode*> q;
        q.push(root);

        int depth = 0;
        while(!q.empty())
        {
            ++depth;
            int qsize = q.size();
            for(int i = 0; i < qsize; ++i)
            {
                TreeNode* top = q.front();
                q.pop();
                if(top->left)   q.push(top->left);
                if(top->right)  q.push(top->right);
                if(top->left == nullptr && top->right == nullptr){
                    return depth;
                }
            }
        }
        return depth;
    }
};