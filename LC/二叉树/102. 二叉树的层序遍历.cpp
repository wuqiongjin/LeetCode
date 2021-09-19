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
 
 //优化版代码
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) 
    {
        queue<TreeNode*> q;
        vector<vector<int>> ans;
        //判断是否为空树
        if(root)
            q.push(root);
        while(!q.empty())
        {
            int levelSize = q.size();   //使用levelSize记录每层的结点的个数
                        //当第1层遍历结束，就相当于把第2层的所有元素push入队列了。即q.size()就是第二层的大小
            vector<int> tmp;
            for(int i = 0; i < levelSize; ++i)
            {
                TreeNode* front = q.front();
                q.pop();
                tmp.push_back(front->val);
                
                if(front->left)
                    q.push(front->left);
                if(front->right)
                    q.push(front->right);
            }
            ans.push_back(tmp);
        }
        return ans;
    }
};




// class Solution {
// public:
//     vector<vector<int>> levelOrder(TreeNode* root) 
//     {
//         if(root == nullptr)
//             return vector<vector<int>>();
//         queue<TreeNode*> q;
//         vector<vector<int>> ans;
//         q.push(root);
//         ans.push_back(vector{root->val});
//         while(!q.empty())
//         {
//             //这里使用循环的目的：
//             //保证q.size()的大小正好为每层元素的个数。第一层的大小就是1，全部pop后，剩下的就是第二层的
//             vector<int> tmp;
//             int sz = q.size();
//             for(int i = 0; i < sz; ++i)
//             {
//                 TreeNode* left = q.front()->left;
//                 TreeNode* right = q.front()->right;
//                 q.pop();
//                 if(left)
//                 {
//                     q.push(left);
//                     tmp.push_back(left->val);
//                 }
                    
//                 if(right)
//                 {
//                     q.push(right);
//                     tmp.push_back(right->val);
//                 }
//             }
//             if(!tmp.empty())
//                 ans.push_back(tmp);  
//         }
//         return ans;
//     }
// };