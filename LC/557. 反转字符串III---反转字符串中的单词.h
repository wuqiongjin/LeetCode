class Solution {
public:
    string reverseWords(string s) 
    {
        // int i = 0;
        int begin = 0, end = 0;
        while(end < s.size())
        {
            if(s[end] == ' ')
            {
                //注意：reverse逆置的区间是左闭右开的
                reverse(s.begin() + begin, s.begin() + end);
                ++end;
                begin = end;
            }
            else
            {
                ++end;
            }
        }
        //最后一段区间别忘了逆置
        reverse(s.begin() + begin, s.end());
        return s;
    }
};