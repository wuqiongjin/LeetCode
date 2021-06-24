class Solution {
public:
    int leftborder(vector<int>& nums, int target)
    {
        int left = 0, right = nums.size() - 1;
        while(left <= right)
        {
            int mid = ((right - left) >> 1) + left;
            if(nums[mid] >= target)
            {
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }
        return left;
    }

    int rightborder(vector<int>& nums, int target)
    {
        int left = 0, right = nums.size() - 1;
        while(left <= right)
        {
            int mid = ((right - left) >> 1) + left;
            if(nums[mid] > target)
            {
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }
        return left;
    }
    //[left, right)
    //left边界是搜查数据的左边界
    //right边界是搜查数据的右边界的下一个位置
    vector<int> searchRange(vector<int>& nums, int target) 
    {
        int leftIndex = leftborder(nums, target);
        int rightIndex = rightborder(nums, target) - 1;
        if(leftIndex > rightIndex)
            return vector<int>{-1, -1};
        return vector<int>{leftIndex, rightIndex};
    }
};