class Solution {
public:
    string countAndSay(int n) 
    {
        //1
        //11
        //21
        //12 11
        //11 12 21
        //31 22 11
        //13 11 22 21
        //11 13 21 32 11
        //31 13 12 11 13 12 21
        string s = "1";     //2个string交互修改赋值 
        if(n == 1)	//n == 1的时候，直接返回。
            return s;

        int i = 1;
        while(i < n)
        {
            //每次重新进入循环，将ans重置为空字符串
            string ans;
            int j = 0;
            //j循环中，统计每个连续相同的字符出现的次数。
            while(j < s.size())
            {
                int count = 1;
                char c = s[j];
                ++j;
                while(j < s.size() && s[j] == c)
                {
                    ++j;
                    ++count;
                }
                ans += to_string(count);
                ans += c;  
            }
            //将ans的值赋给s，让s进行下一次的操作
            swap(ans, s);
            ++i;
        }
        return s;
    }
};