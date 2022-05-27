class Solution {
public:
    //原地哈希
    //题里面条件给出"长度为n的数组, 所有整数都在[1, n]"
    //这意味着, 如果一个数字出现2次，那么在[1, n]中必然会多一个空的位置(多一个数字一次都没出现)
    //原地哈希的解题思路:
    //将每个数据val放在val-1下标处; 实际做法就是交换nums[index]与nums[nums[index] - 1]
    //从头到尾遍历整个数组，把所有应该放到对应位置的数据都放到对应位置
    //最后的结果就是: 不在对应位置的数字就是出现2次的, 因为它们占了那些没有出现的数字的位置
    vector<int> findDuplicates(vector<int>& nums) 
    {
        vector<int> res;
        int index = 0;
        while(index < nums.size())
        {
            while(nums[index] != nums[nums[index] - 1])
            {
                swap(nums[index], nums[nums[index] - 1]);
            }
            ++index;
        }
        
        for(int i = 0; i < nums.size(); ++i)
        {
            if(nums[i] != i + 1){
                res.push_back(nums[i]);
            }
        }
        return res;
    }

    // vector<int> findDuplicates(vector<int>& nums) 
    // {
    //     unordered_map<int,int> umii;
    //     for(int e : nums)
    //     {
    //         umii[e]++;
    //     }
        
    //     vector<int> res;
    //     for(auto& e : umii)
    //     {
    //         if(e.second == 2){
    //             res.push_back(e.first);
    //         }
    //     }
    //     return res;
    // }
};