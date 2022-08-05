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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth == 1){
            TreeNode* newNode = new TreeNode(val);
            newNode->left = root;
            return newNode;
        }

        queue<TreeNode*> q;
        q.push(root);
        int curDepth = 0;
        while(!q.empty())
        {
            int levelSize = q.size();
            ++curDepth;      
            if(curDepth == depth - 1){
                TreeNode* top = q.front();
                q.pop();
                TreeNode* left = top->left;
                TreeNode* right = top->right;
                
                TreeNode* newLeftNode = new TreeNode(val);
                newLeftNode->left = left;
                top->left = newLeftNode;

                TreeNode* newRightNode = new TreeNode(val);
                newRightNode->right = right;
                top->right = newRightNode;

                break;
            }

            for(int i = 0; i < levelSize; ++i)
            {
                TreeNode* top = q.front();
                q.pop();
                if(top->left)   q.push(top->left);
                if(top->right)  q.push(top->right);
            }
        }
        return root;
    }
};