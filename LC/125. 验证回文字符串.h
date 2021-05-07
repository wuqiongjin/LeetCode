class Solution {
public:
    bool isPalindrome(string s) 
    {
        for(auto& ch : s)
        {
            //将所有大写字母转为小写字母
            // ch = tolower(ch);  //可行。。但是效率比较低
            if(isupper(ch))
                ch += 32;	//注意！这里不能用tolower函数，tolower函数的形参是int ch (传值)，并 不能改变 原来的string中的ch
               
        }
        int begin = 0, end = s.size() - 1;
        while(begin < end)
        {
            while(begin < end && !isalnum(s[begin]))
                ++begin;
            while(begin < end && !isalnum(s[end]))
                --end;

            if(s[begin] != s[end])
                return false;
            else
            {
                ++begin;
                --end;
            }
        }
        return true;
    }
};