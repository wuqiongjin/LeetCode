//双下标作法，时间复杂度O(M * N)

// class Solution {
// public:
//     bool repeatedSubstringPattern(string s) 
//     {
//         int s1  = 0, s2 = 1, cur = 1;
//         int len = 0, count = 0;
//         while(s2 < s.size())
//         {
//             s2 = cur;
//             if(s[s2] == s[s1])
//             {
//                 len = s2 - s1;

//                 count = 0;
//                 while(s2 < s.size() && s[s2] == s[s1])
//                 {
//                     ++count;
//                     ++s2;
//                     ++s1;
//                 }
//             }
//             //这里需要注意，必须使用count和len去作判断。不然像 aba这样的，会出现问题
//             if(count != 0 && count % len == 0 && s2 == s.size())
//                 return true;
//             s1 = 0;
//             ++cur;
//         }
//         return false;
//     }
// };


//KMP

class Solution {
public:
    void getNext(vector<int>& next, const string& s)
    {
        int j = 0;
        next[0] = j;
        for(int i = 1; i < s.size(); ++i)
        {
            //回溯
            while(j > 0 && s[i] != s[j])
                j = next[j - 1];
            //相等的话，++j
            if(s[i] == s[j])
                ++j;
            //更新i位置处的next数组值
            next[i] = j;
        }
    }

    bool repeatedSubstringPattern(string s) 
    {
        int len = s.size();
        if(len == 1)
            return false;
        vector<int> next(len);
        getNext(next, s);
        // int max = next[0];
        // for(auto e : next)
        // {
        //     if(e > max)
        //         max = e;
        // }
        // if(max != next[len - 1])
        //     return false;

        //判断条件：
        //利用next数组求出最长相等的前缀后缀 这个最大的next值，必然是最后一个元素 next[len - 1]
        //用数组的总长度 len - next[len - 1]得出来的就是最小的重复子字符串的长度
        //如果len % 重复子字符串的长度 == 0，那么就是重复的子字符串，否则就不是
        if(next[len - 1] > 0 && len % (len - next[len - 1]) == 0)
            return true;
        else
            return false;
    }
};