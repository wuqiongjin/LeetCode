class Solution {
public:
	//字典序算法
    void nextPermutation(vector<int>& nums) 
    {
        int n = nums.size() - 1;
        //1. 从右向左，找第一个左邻 < 右邻 的左邻的位置
        int a = 0, b = 0;
        bool findA = false;
        for(int i = n; i > 0; --i)
        {
            if(nums[i - 1] < nums[i])
            {
                findA = true;
                a = i - 1;
                break;
            }
        }
        //如果找不到 左邻 < 右邻。说明该数组是降序排列，return结束
        if(!findA)
        {
            reverse(nums.begin(), nums.end());
            return;
        }

        //2. 从右向左，找第一个大于nums[a]的位置
        for(int i = n; i >= 0; --i)
        {
            if(nums[i] > nums[a])
            {
                b = i;
                break;
            }
        }
        
        //3. 交换a和b位置对应的值
        swap(nums[a], nums[b]);

        //4. 将a后面的所有数，由小到大排序 (实际上就是逆置)
        reverse(nums.begin() + a + 1, nums.end());
    }
};