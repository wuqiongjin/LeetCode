class Solution {
public:
    void getNext(int* next, const string& s)
    {
        int j = 0;
        next[0] = j;
    
        for(int i = 1; i < s.size(); ++i)
        {
            while(j > 0 && s[j] != s[i])
            {
                j = next[j - 1];
            }

            if(s[j] == s[i]){
                ++j;
            }
            next[i] = j;
        }
    }

    bool repeatedSubstringPattern(string s) 
    {
        //思路: 根据next数组的值判断 字符串s是否能被重复的子串构成
        int next[s.size()];
        getNext(next, s);

        //方法1. 笨方法: 取重复的pattern串，然后判断字符串是否能被pattern组成
        // int patternLength = s.size() - next[s.size() - 1];
        // // next[s.size() - 1]不能为0!!!
        // if(patternLength == s.size()){
        //     return false;
        // }
        // string pattern = s.substr(0, patternLength);

        // int i = patternLength;
        // while(i < s.size())
        // {
        //     if(s.substr(i, patternLength) != pattern){
        //         return false;
        //     }
        //     i += patternLength;
        // }
        // return true;


        //方法2. 利用next数组的值进行模运算
        int patternLength = s.size() - next[s.size() - 1];
        if(patternLength == s.size()){  //next[s.size() - 1]值不能为0
            return false;
        }

        if(s.size() % patternLength == 0){
            return true;
        }
        return false;
    }
};