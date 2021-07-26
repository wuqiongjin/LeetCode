class Solution {
public:
    bool isNumber(string s) 
    {
        //跳过空格
        int i = 0;
        while(i < s.size() && s[i] == ' ')
            ++i;
        if(i == s.size())
            return false;

        //跳过结尾空格
        int end = s.size() - 1;
        while(end >= 0 && s[end] == ' ')
            --end;

        //跳过符号
        if(s[i] == '-' || s[i] == '+')
            ++i;

        // if(s[i] == 'E' || s[i] == 'e')
        //     return false;

        bool point = false;
        bool Echar = false;
        
        //判断小数/整数 + E
        for(; i <= end; ++i)
        {
            if(!isdigit(s[i]) && s[i] != '.' && s[i] != 'e' && s[i] != 'E')
                return false;

            if(s[i] == '.')
            {
                if(point)
                    return false;
                point = true;
                if(i - 1 >= 0)
                {
                    if((!isdigit(s[i - 1]) && i + 1 > end) || (!isdigit(s[i - 1]) && !isdigit(s[i + 1])))
                         return false;
                }
                else
                {
                    if(i + 1 > end || !isdigit(s[i + 1]))
                        return false;
                }
            }
            
            if(s[i] == 'e' || s[i] == 'E')
            {
                //别忘了跳过E
                ++i;
                //E后面若没有东西，返回false
                if(i > end || !Echar)
                    return false;
                break;
            }
            Echar = true;
        }

        //没有E的情况下，走到了结尾。返回true
        if(i > end)
            return true;

        //检查E后面的是否为整数
        //跳过符号
        if(s[i] == '-' || s[i] == '+')
            ++i;
        //如果跳过符号后就到了结尾，返回false
        if(i > end)
            return false;

        //检查是否为整数
        while(i <= end)
        {
            if(!isdigit(s[i++]))
                return false;
        }   
        //只有走到了结尾的才是true
        if(i > end) 
            return true;
        else
            return false;
    }
};