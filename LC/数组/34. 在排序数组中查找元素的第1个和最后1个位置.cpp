//3 刷
class Solution {
public:
    //情况1: [1,2,3,5]  找0或者6, 此时会超出数组的两边    return {-1, -1}
    //情况2: [1,2,3,5]  找4, 此时在数组的中间不存在该元素 return {-1, -1}
    //情况3: [1,2,3,5]  找3, 此时数组中存在该元素        return {2, 2}
    //寻找左边界
    int LeftBorder(vector<int>& nums, int target)
    {
        int left = 0, right = nums.size() - 1;
        int lborder = -2;
        while(left <= right)
        {
            int mid = left + (right - left) / 2;
            if(nums[mid] < target){
                left = mid + 1;
            }
            else if(nums[mid] >= target){
                right = mid - 1;
                lborder = right;
            }
        }
        return lborder;
    }

    //寻找右边界
    int RightBorder(vector<int>& nums, int target)
    {
        int left = 0, right = nums.size() - 1;
        int rborder = -2;
        while(left <= right)
        {
            int mid = left + (right - left) / 2;
            if(nums[mid] <= target){
                left = mid + 1;
                rborder = left;
            }
            else if(nums[mid] > target){
                right = mid - 1;
            }
        }
        return rborder;
    }

    vector<int> searchRange(vector<int>& nums, int target) 
    {
        int lborder = LeftBorder(nums, target);
        int rborder = RightBorder(nums, target);

        //处理情况1 (数组中不存在该元素, 且超过数组的边界)
        if(lborder == -2 || rborder == -2){
            return {-1, -1};
        }
        
        //处理情况3
        if(rborder - lborder > 1){
            return {lborder + 1, rborder - 1};
        }

        //情况2 (数组中不存在该元素)
        return {-1, -1};        
    }
};





// 1刷
// class Solution {
// public:
    // int leftborder(vector<int>& nums, int target)
    // {
        // int left = 0, right = nums.size() - 1;
        // while(left <= right)
        // {
            // int mid = ((right - left) >> 1) + left;
            // if(nums[mid] >= target)
            // {
                // right = mid - 1;
            // }
            // else
            // {
                // left = mid + 1;
            // }
        // }
        // return left;
    // }

    // int rightborder(vector<int>& nums, int target)
    // {
        // int left = 0, right = nums.size() - 1;
        // while(left <= right)
        // {
            // int mid = ((right - left) >> 1) + left;
            // if(nums[mid] > target)
            // {
                // right = mid - 1;
            // }
            // else
            // {
                // left = mid + 1;
            // }
        // }
        // return left;
    // }
    // //[left, right)
    // //left边界是搜查数据的左边界
    // //right边界是搜查数据的右边界的下一个位置
    // vector<int> searchRange(vector<int>& nums, int target) 
    // {
        // int leftIndex = leftborder(nums, target);
        // int rightIndex = rightborder(nums, target) - 1;
        // if(leftIndex > rightIndex)
            // return vector<int>{-1, -1};
        // return vector<int>{leftIndex, rightIndex};
    // }
// };









//2刷

//这里找的区间是[left, right]
class Solution {
public:
    //思路：分开寻找Left左边界和Right右边界
    int Left(vector<int>& nums, int target)
    {
        int left = 0, right = nums.size() - 1;
        while(left <= right)
        {
            int mid = ((right - left) >> 1) + left;
            if(nums[mid] < target)
            {
                left = mid + 1;
            }
            else if(nums[mid] >= target)    //左边界就是满足target的第一个元素
            {
                right = mid - 1;
            }
        }
        return left;
    }

    int Right(vector<int>& nums, int target)
    {
        int left = 0, right = nums.size() - 1;
        while(left <= right)
        {
            int mid = ((right - left) >> 1) + left;
            if(nums[mid] <= target)         //右边界就是满足target的最后一个元素
            {
                left = mid + 1;
            }
            else if(nums[mid] > target)
            {
                right = mid - 1;
            }
        }
        return right;
    }

    vector<int> searchRange(vector<int>& nums, int target) 
    {
        int left = Left(nums, target);
        int right = Right(nums, target);
        //判断下表的有效性
        if(left > right)
            return vector<int>{-1, -1};
        return vector<int>{left, right};
    }
};