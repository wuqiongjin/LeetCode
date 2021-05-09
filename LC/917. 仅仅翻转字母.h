class Solution {
public:
    string reverseOnlyLetters(string S) 
    {
        int begin = 0, end = S.size() - 1;
        while(begin < end)
        {
            //找出是字母的
            while(begin < end && !isalpha(S[begin]))
                ++begin;
            while(begin < end && !isalpha(S[end]))
                --end;
            //进行交换
            if(begin < end)
            {
                swap(S[begin], S[end]);
                //千万别忘了，交换完了之后 还要将begin和end进行++和--
                ++begin;
                --end;
            }
        }
        return S;
    }
};