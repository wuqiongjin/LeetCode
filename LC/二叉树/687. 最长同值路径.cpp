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
    //思路:
    //要看懂题目问的是什么!!! 问的是"两个结点 之间的 最长相等值 路径"
    //因此, 我们在遍历的过程中, 针对每一个结点, 判断其左子树和右子树
    //如果root->left && root->left->val == root->val, 那么left路径++; 否则left = 0;
    //如果root->right && root->right->val == root->val, 那么right路径++; 否则right = 0;
    //我们最终res取结果的时候, 取的是left路径到right路径的长度之和, 此时相当于起点是left路径的某一子节点, 终点是right路径的某一子节点
    //我们递归返回的时候, 需要返回max(left, right), 因为当前结点对于上一层来说只能算做一条路径, 不能取left+right,取了的话就不是一条路径了!
    int traverse(TreeNode* root){
        if(root == nullptr) return 0;
        int left = traverse(root->left);
        int right = traverse(root->right);
        
        if(root->left && root->left->val == root->val){
            ++left;
        }
        else{
            left = 0;
        }
        
        if(root->right && root->right->val == root->val){
            ++right;
        }
        else{
            right = 0;
        }
        res = max(res, left + right);
        return max(left,right);
    }

    int longestUnivaluePath(TreeNode* root) {
        traverse(root);
        return res;
    }

    int res = 0;
};