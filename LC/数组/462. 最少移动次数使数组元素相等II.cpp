class Solution {
public:
    //选取中位数的时候, 所需要移动的次数是最少的(反证法, 如果不选中位数会怎么样)
    int minMoves2(vector<int>& nums) 
    {
        sort(nums.begin(), nums.end());
        int res = 0;
        int left = 0, right = nums.size() - 1;
        while(left < right)
        {
            res += nums[right--] - nums[left++]; 
        }
        return res;
    }
};