class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) 
    {
        //将所有结果异或在一起，然后去找二进制位为1的那位作为分组条件
        int ret = 0;
        for(auto e : nums)
        {
            ret ^= e;
        }

        //找出任意一个为1的位置
        int i = 0;
        while(!((ret >> i) & 1))
        {
            ++i;
        }

        //进行分组，然后找出只出现1次的2个数
        vector<int> val(2);
        for(auto e : nums)
        {
            if((e >> i) & 1)
            {
                val[0] ^= e;
            }
            else
            {
                val[1] ^= e;
            }
        }
        return val;
    }
};