class Solution {
public:
    int firstUniqChar(string s) 
    {
        //使用映射的思路；因为字母只有26个，所以可以创建一个大小为27的数组，用来存放每个字母出现的次数
        //思路和计数排序相同！
        int alpha[27] = {0};
        int i = 0;
        while(i < s.size())
        {
            ++alpha[s[i] - 'a'];
            ++i;
        }
        i = 0;
        while(i < s.size())
        {
            if(alpha[s[i] - 'a'] == 1)
                return i;
            ++i;
        }   
        return -1;
    }
};