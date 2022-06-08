class Solution {
public:
    //笨方法, 转化为数组
    TreeNode* arrayToBST(vector<int>& nums, int left, int right){
        if(left >= right){
            return nullptr;
        }
        int mid = left + (right - left) / 2;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = arrayToBST(nums, left, mid);
        root->right = arrayToBST(nums, mid + 1, right);

        return root;
    }

    TreeNode* sortedListToBST(ListNode* head) {
        vector<int> nums;
        ListNode* cur = head;
        while(cur)
        {
            nums.push_back(cur->val);
            cur = cur->next;
        }
        return arrayToBST(nums, 0, nums.size());
    }
};


class Solution {
public:
    //双指针找中点 + 递归
    ListNode* getMidNode(ListNode* left, ListNode* right){
        ListNode* fast = left, *slow = left;
        while(fast != right && fast->next != right){//注意!!!这里是fast != right (不是!= nullptr)
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }

    TreeNode* buildBST(ListNode* left, ListNode* right){
        if(left == right){
            return nullptr;
        }

        ListNode* mid = getMidNode(left, right);    //注意, 这里的类型是ListNode, 要转换为TreeNode
        TreeNode* root = new TreeNode(mid->val);
        root->left = buildBST(left, mid);
        root->right = buildBST(mid->next, right);

        return root;
    }

    TreeNode* sortedListToBST(ListNode* head) {
        return buildBST(head, nullptr);        
    }
};