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
    bool Find(TreeNode* root, TreeNode* target)
    {
        if(root == nullptr)
            return false;

        //递归遍历子树，找target是否存在在root的子树中
        return root == target || 
        (Find(root->left, target) || Find(root->right, target));
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
    {
        //1. q是p的孩子，那么p就是祖先 或 p是q的孩子，那么q就是祖先。
        //2. p和q分别在root的左子树 和 右子树，那么root就为他们的祖先
        //3. p和q都在root的左边 或 都在右边，继续递归找分歧点
        if(root == nullptr)
            return nullptr;
        //1. 祖先要么是p，要么是q。这里只能返回root
        if(root == p || root == q)
            return root;
        
        //巧设4个变量确定p和q所在的子树
        bool pInLeft, pInRight, qInLeft, qInRight;
        pInLeft = Find(root->left, p);
        pInRight = !pInLeft;
        qInLeft = Find(root->left, q);
        qInRight = !qInLeft;

        //2. 确定p和q异树，那么root就是它们的公共祖先
        if((pInLeft && qInRight) || (pInRight && qInLeft))
            return root;
        
        //3. 确定p和q同树，继续递归寻找
        if(pInLeft && qInLeft)
            return lowestCommonAncestor(root->left, p, q);
        if(pInRight && qInRight)
            return lowestCommonAncestor(root->right, p, q);
            
        //该函数必须要有返回值，所以这里写了个返回nullptr。但实际上没什么意义
        return nullptr;
    }
};