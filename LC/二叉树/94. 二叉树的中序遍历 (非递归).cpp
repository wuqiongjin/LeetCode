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
    vector<int> inorderTraversal(TreeNode* root) 
    {
        stack<TreeNode*> st;
        vector<int> ans;

        while(root || !st.empty())
        {
            //1. 先去遍历左路结点，但是不访问
            while(root != nullptr)
            {
                st.push(root);
                root = root->left;
            }
            
            //2. 左路结点走到头后，从栈中取出并访问
            //3. 继续遍历左路结点的右子树（即将非空右子树入栈）
            TreeNode* top = st.top();   //※ 这里最好另创建一个变量top用来存储。不推荐直接拿root去接收
            st.pop();
            ans.push_back(top->val);
            
            root = top->right;
        }
        return ans;
    }
};