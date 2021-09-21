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
    //只使用1个prev指针去记录上一个"访问"的结点   (访问的意思是添加到ans结果中)
    //由此判断上一个访问的结点在当前结点的左边还是右边
    //如果上一个访问的结点在当前结点的右边，那么说明该节点的左右子树已经全部访问了，可以访问当前节点了
    vector<int> postorderTraversal(TreeNode* root) 
    {
        stack<TreeNode*> st;
        vector<int> ans;
        TreeNode* prev = nullptr;   //记录上一次"访问"的结点

        while(root || !st.empty())
        {
            while(root != nullptr)
            {
                st.push(root);
                root = root->left;
            }

            //这里的top变量必须要创建！！！很关键，不能拿root去接收，接收的话就错了。。。
            TreeNode* top = st.top();
            if(top->right == nullptr || top->right == prev) //判断上一个访问的结点是否在当前结点的右边
            {
                ans.push_back(top->val);
                prev = top; //记录上一个访问的结点
                st.pop();
            }
            else
            {
                root = top->right;
            }
        }
        return ans;
    }
};



// class Solution {
// public:
//     //2. flag栈去判断右子树是否访问
//     vector<int> postorderTraversal(TreeNode* root) 
//     {
//         stack<TreeNode*> st;
//         vector<int> ans;
//         stack<int> flag;

//         while(root || !st.empty())
//         {
//             while(root != nullptr)
//             {
//                 st.push(root);
//                 flag.push(0);
//                 root = root->left;
//             }
            
//             //※※※必须要另外创建一个变量top去接收st.top()，不要直接拿root去接收 ※※※ 
//             //否则，root在本不该改变它的值的地方，就会发生改变。然后就错了。。。
//             TreeNode* top = st.top();
//             if(flag.top() == 1 || top->right == nullptr)
//             {
//                 ans.push_back(top->val);
//                 st.pop();
//                 flag.pop();
//             }
//             else
//             {
//                 flag.top() = 1;
//                 root = top->right;
//             }
//         }
//         return  ans;
//     }
// };