class Solution {
public:
    string compressString(string S) 
    {
        //3107 -> 3 1 0 7
        
        //遍历一遍，统计每个单词的次数。然后存到ans中
        int index = 0;
        string ans;
        int i = 0;
        while(i < S.size())
        {
            int count = 1;
            char c = S[i];
            ++i;
            while(i < S.size() && S[i] == c)
            {
                ++i;
                ++count;
            }
            ans += c;
            //将整形的数据count变为string类型。（不用这个函数也得自己实现个）
            //要考虑到count可能是10+，100+等
            ans += to_string(count);
        
        }
        //S的长度小于等于ans时，直接返回S
        if(S.size() <= ans.size())
            return S;
        else
            return ans;
    }
};