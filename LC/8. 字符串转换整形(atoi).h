class Solution {
public:
    int myAtoi(string s) 
    {
        bool symbol = true;
        //丢弃空格
        int begin = 0;
        while(begin < s.size() && s[begin] == ' ')
            ++begin;
        //确定正负号
        if(s[begin] == '-')
        {
            symbol = false;
            ++begin;
        }
        else if(s[begin] == '+')
            ++begin;
        else{}
        //确定结尾end  结尾条件，遇到不是数字字符就结束
        int end = begin;
        while(end < s.size() && isdigit(s[end]))
            ++end;

        //判断是否没有数字字符（begin的下一个如果不是数字字符也结束）
        if(begin == end)
            return 0;
        //转化为整形
        long res = 0;
        while(begin < end)
        {
            res = res * 10 + s[begin] - '0';
            ++begin;
            //超出范围直接返回
            if(res > INT_MAX)
            {
                if(symbol)
                    return INT_MAX;
                else
                    return INT_MIN;
            }
        }
        if(symbol)
            return res;
        else
            return res * -1;
    }
};