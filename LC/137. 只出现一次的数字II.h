class Solution {
public:
    int singleNumber(vector<int>& nums) 
    {
        //存储每个二进制位
        vector<int> bit(32);
        //统计二进制位总和
        for(auto e : nums)
        {
            for(size_t i = 0; i < 32; ++i)
            {
                if(((e >> i) & 1))
                {
                   ++bit[i];
                }
            }
        }
        //将二进制的每位进行对3取模。然后将结果按位与等于给 val 
        int val = 0;
        for(size_t i = 0; i < 32; ++i)
        {
            // bit[i] %= 3;
            // val |= (bit[i] << i);//这里bit[i] << i 就是相当于给val对应的位 |= 对应的值了

            //把结果为1的位异或到结果上
            if(bit[i] % 3 == 1)
            {
                val |= (1 << i);
            }
        }
        return val;
    }
};