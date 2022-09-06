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
    //思路:
    //首先, 遍历整棵树, 记录每个节点的父亲节点
    //然后dfs, 以target为根结点, 向left、right、parent递归遍历, 为了保证不会掉头遍历, 我们需要传入一个from来告知我们上一个遍历的节点是什么, 我们需要保证接下来遍历的节点不能使上一个节点
    void recordParent(TreeNode* root){
        if(root->left){
            umit[root->left->val] = root;
            recordParent(root->left);
        }

        if(root->right){
            umit[root->right->val] = root;
            recordParent(root->right);
        }
    }

    void dfs(TreeNode* cur, TreeNode* from, int depth, int k){
        if(cur == nullptr)  return;
        if(depth == k){
            res.push_back(cur->val);
            return;
        }

        if(cur->left != from){
            dfs(cur->left, cur, depth + 1, k);
        }

        if(cur->right != from){
            dfs(cur->right, cur, depth + 1, k);
        }

        if(umit[cur->val] != from){
            dfs(umit[cur->val], cur, depth + 1, k);
        }
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        recordParent(root);
        dfs(target, nullptr, 0, k);
        return res;
    }

    unordered_map<int,TreeNode*> umit;
    vector<int> res;
};