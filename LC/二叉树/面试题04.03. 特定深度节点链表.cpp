/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

//本题：层序遍历(记录深度) + 链表的连接

class Solution {
public:
    vector<ListNode*> listOfDepth(TreeNode* tree) 
    {
        queue<TreeNode*> q;
        vector<ListNode*> ans;
        if(tree == nullptr)
            return ans;
        q.push(tree);
        while(!q.empty())
        {
            ListNode* head = nullptr;
            ListNode* prev = nullptr;
            int levelSize = q.size();
            for(int i = 0; i < levelSize; ++i)
            {
                TreeNode* top = q.front();
                ListNode* cur = new ListNode(top->val);
                q.pop();

                //链表的创建需要每次判断头结点是否为nullptr
                if(head == nullptr)
                {
                    head = cur;
                    // prev = head;
                }
                else
                {
                    prev->next = cur;
                    // prev = cur;
                    // cur = cur->next;
                }
                prev = cur;
                cur = cur->next;    //这句话其实也没用

                if(top->left)
                    q.push(top->left);
                if(top->right)
                    q.push(top->right);
            }
            ans.push_back(head);
        }
        return ans;
    }
};