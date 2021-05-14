class Solution {
public:
    string reverseStr(string s, int k) 
    {
        //a b c d e f g      k = 4
        //d c b a e f g

        //a b c d e f g h i j    k = 4。先翻转前8个中的前4个字符，，
        //d c b a e f g h               然后再反转8 ~ 16个中的前4个字符，这里由于8~16个字符不满4个，所以翻转剩下的所有字符
        //j i
        //d c b a e f g h j i

        int start = 0;
        while(start < s.size())
        {
            //剩余的长度不足k的全部翻转  ---这里不用考虑不足2k的，因为不足2k的话，这轮还是翻转前k个，下一回它就是不足2k - k个了
            if(start + k > s.size())
            {
                reverse(s.begin() + start, s.end());
            }
            else
            {
                reverse(s.begin() + start, s.begin() + start + k);
            }
            start += 2*k;
        }
        return s;
    }
};