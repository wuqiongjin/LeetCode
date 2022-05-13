/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/**			与 572. 另一颗树的子树 基本一样		**/

class Solution {
public:
    //dfs?
    //我的思路:
    //遍历A树的每个结点，然后让每个结点与B树的根结点开始往下比较。
    //一旦B树遍历到了nullptr, 那么说明B是A的子结构.
    bool _isSubStructure(TreeNode* A, TreeNode* B)
    {
        if(B == nullptr){
            return true;
        }
        if(A == nullptr){
            return false;
        }

        if(A->val != B->val){
            return false;
        }

        return _isSubStructure(A->left, B->left)
            && _isSubStructure(A->right, B->right);
    }

    bool isSubStructure(TreeNode* A, TreeNode* B) 
    {
        //题里要求: 空树不为任何树的子树! (所以B不能为空, A为空也不行的)
        if(A == nullptr || B == nullptr){
            return false;
        }

        return _isSubStructure(A, B)
            || isSubStructure(A->left, B)
            || isSubStructure(A->right, B);
    }
};