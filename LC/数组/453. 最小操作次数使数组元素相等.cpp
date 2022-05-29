class Solution {
public:
    //对n-1个数加1,就等价于对1个数-1
    //所以, 我们只要找出最小的那个数, 然后遍历数组, 让每个数都减到最小的数即可
    int minMoves(vector<int>& nums) 
    {
        int minValue = *min_element(nums.begin(), nums.end());
        int res = 0;
        for(int e : nums)
        {
            res += e - minValue;
        }
        return res;
    }
};