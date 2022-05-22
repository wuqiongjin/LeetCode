//1. Carl方法: 前序顺序: 根 左 右 --> 根 右 左 (入栈顺序需要调整一下)
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) 
    {
        if(root == nullptr) return {};
        
        vector<int> res;
        stack<TreeNode*> st;
        st.push(root);

        while(!st.empty())
        {
            TreeNode* node = st.top();
            res.push_back(node->val);
            st.pop();
            
            if(node->right){
                st.push(node->right);
            }

            if(node->left){
                st.push(node->left);
            }
        }

        return res;
    }
};


//2. 杭哥思路
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