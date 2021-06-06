// class Solution {
// public:
//     //效率没有横向扫描高。。
//     //从空字符串开始添加共同部分
//     string longestCommonPrefix(vector<string>& strs) 
//     {
//         if(strs.size() == 1)
//             return strs[0];
//         int index = 0;
//         string res;
//         //先求出所有字符串中最短的那个的长度
//         int minlength = strs[0].size();
//         for(auto e : strs)
//         {
//             if(minlength > e.size())
//                 minlength = e.size();   
//         }

//         while(index < minlength)
//         {
//             for(int i = 0; i < strs.size() - 1; ++i)
//             {
//                 //该字符串如果没有符合共同的条件。直接return当前的res
//                 if(strs[i][index] != strs[i + 1][index])
//                     return res;
//             }
//             //如果该字符在每个字符串中都处于同一位置，那么将它添加进入res中
//             res += strs[0][index];
//             ++index;
//         }
//         return res;
//     }
// };

//1. 横向扫描法

class Solution {
public:
    //比较函数，返回两个string的共同部分(用substr返回)
    string longestCommonPrefix(string& prefix, string& cmp)
    {
        int index = 0;
        for(;index < min(prefix.size(), cmp.size()); ++index)
        {
            if(prefix[index] != cmp[index])
                break;
        }
        return prefix.substr(0, index);
    }

    string longestCommonPrefix(vector<string>& strs) 
    {
        string prefix = strs[0];
        for(int i = 1; i < strs.size(); ++i)
        {
            //更新最长prefix
            prefix = longestCommonPrefix(prefix, strs[i]);
            //没有相同部分，直接返回空字符串""
            if(!prefix.size())
                return "";            
        }
        return prefix;
    }
};


//2. 纵向扫描法

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs)
    {
        if(!strs.size())
            return "";
        int len = strs[0].size();
        int count = strs.size();

        for(int j = 0; j < len; ++j)
        {
            //取第1个string的每一个字符作为c用来判断
            char c = strs[0][j];
            for(int i = 1; i < count; ++i)
            {
                //如果大于该字符的长度  或者 与c不相等。直接return共同部分
                if(strs[i].size() == j || strs[i][j] != c)
                    return strs[0].substr(0, j);
            }
        }
        return strs[0];
    }
};