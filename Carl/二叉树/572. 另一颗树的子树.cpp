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
    //dfs
    //遍历root树的每个节点, 然后让root的每个结点都与subRoot整棵树进行比较
    bool _isSameTree(TreeNode* root, TreeNode* subRoot)
    {
        if(root == nullptr && subRoot == nullptr){
            return true;
        }
        if(root == nullptr || subRoot == nullptr){
            return false;
        }
        if(root->val != subRoot->val){
            return false;
        }
        return _isSameTree(root->left, subRoot->left)
            && _isSameTree(root->right, subRoot->right);
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) 
    {
        if(root == nullptr){    //root为空一定是false (因为题里说subRoot不为空)
            return false;
        }

        return _isSameTree(root, subRoot) //根
            || isSubtree(root->left, subRoot)   //左
            || isSubtree(root->right, subRoot); //右
    }
};