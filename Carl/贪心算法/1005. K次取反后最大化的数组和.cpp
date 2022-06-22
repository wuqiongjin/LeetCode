class Solution {
public:
    //贪心算法:
    //1. 先尝试将所有负数变为正数
    //2. 如果k仍不为0，此时找到最小的非负数，把它变成非负数(判断k是否为奇数, 偶数就不用管了)
    int largestSumAfterKNegations(vector<int>& nums, int k) 
    {
        //1.先按照abs值降序排列(后续我们是从0下标开始将负数变为正数的)
        sort(nums.begin(), nums.end(), [](int x, int y){
            return abs(x) > abs(y);
        });
        
        //2. k-- 遍历整个数组，尝试将所有负数转为正数
        for(int i = 0; i < nums.size() && k != 0; ++i)
        {
            if(nums[i] < 0)
            {
                --k;
                nums[i] *= -1;
            }
        }
        
        //3.k为奇数(说明k肯定不为0), 需要将绝对值最小的非负数变为非正数
        if(k % 2 != 0){
            nums[nums.size() - 1] *= -1;    //降序排列, 绝对值最小的在最后
        }

        int res = 0;
        for(int a : nums)
            res += a;
        return res;
    }
};

// class Solution {
// public:
//     int Sum(vector<int>& nums)
//     {
//         int res = 0;
//         for(auto e : nums)
//         {
//             res += e;
//         }
//         return res;
//     }

//     int largestSumAfterKNegations(vector<int>& nums, int k) 
//     {
//         sort(nums.begin(), nums.end());

//         int i  = 0;
//         while(k)
//         {
//             //当i超过数组大小时，证明所有负数都已经变成了正数了

//             //存在负数，就将负数变为正数
//             if(i < nums.size() && nums[i] < 0){
//                 nums[i] *= -1;
//                 ++i;
//                 k--;    //记得k--
//             }
//             else{
//                 //当全变为正数时，先整体排序一下，为了方便"在k还是奇数时，将最小的非负数变为非正数"
//                 sort(nums.begin(), nums.end());
//                 if(k % 2 == 0){
//                     return Sum(nums);
//                 }
//                 else{
//                     nums[0] *= -1;
//                     return Sum(nums);
//                 }
//             }
//         }
//         return Sum(nums);
//     }
// };