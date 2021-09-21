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
    vector<int> preorderTraversal(TreeNode* root) 
    {
        stack<TreeNode*> st;
        vector<int> ans;

        while(root || !st.empty())
        {
            //把左路全部入栈
            while(root != nullptr)
            {
                st.push(root);
                ans.push_back(root->val);
                root = root->left;
            }
            
            //左路走到头了
            //该遍历左路结点的 右子树。
            //如果右子树不是空，就会再下一轮循环中入栈
            //右子树为空下一轮会取栈中的下一个元素的右子树
            
            TreeNode* top = st.top();   ////※ 这里最好另创建一个变量top用来存储。不推荐直接拿root去接收
            st.pop();
            root = top->right;
        }

        return ans;        
    }
};