class Solution {
public:
    int _romanToInt(char c)
    {
		//可以考虑用unorder_map
        vector<int> v{1, 5, 10, 50, 100, 500, 1000};

        switch(c)
        {
            case 'I':
                return v[0];
            case 'V':
                return v[1];
            case 'X':
                return v[2];
            case 'L':
                return v[3];
            case 'C':
                return v[4];
            case 'D':
                return v[5];
            case 'M':
                return v[6];
        }
        return 0;
    }

//差不多得了，就挺无语的。我是逆着加的。。。所以会出现问题。
//正常通过罗马转换成数字的，应该从正向来。。。
    // int romanToInt(string s) {
    //     int len = s.size();

    //     int start = len - 2;
    //     int end = len - 1;
    //     int res = 0;
    //     while(start >= 0)
    //     {
    //         if(_romanToInt(s[start]) > _romanToInt(s[end]))
    //         {
    //             res += _romanToInt(s[start]) + _romanToInt(s[end]);
    //             end = start - 1;
    //         }
    //         else if (_romanToInt(s[start]) < _romanToInt(s[end]))
    //         {
    //             res += _romanToInt(s[end]) - _romanToInt(s[start]);
    //             end = start - 1;
    //         }
    //         else    //相等的情况，需要进一步判断累加
    //         {
    //             while(start >= 0 &&_romanToInt(s[start]) == _romanToInt(s[end]))
    //             {
    //                 res += _romanToInt(s[end]);
    //                 end = start;
    //                 --start;
    //             }
    //         }
    //         start = end - 1;
    //     }
    //     if(end == 0)
    //         res += _romanToInt(s[end]);
    //     return res;
    // }




    //正确答案
    int romanToInt(string s)
    {
        int len = s.size();
        int i = 0;
        int res = 0;
        while(i < len)
        {
            //如果当前字符的数字 小于<  下一个字符。那么取它的相反数加到res上去
            if(_romanToInt(s[i]) < _romanToInt(s[i + 1]))
                res += -_romanToInt(s[i]);
            else
                res += _romanToInt(s[i]);
            ++i;
        }
        return res;
    }
};