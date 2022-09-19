class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        int hash[128] = { 0 };
        int res = -1;
        for(int i = 0; i < s.size(); ++i)
        {
            if(hash[s[i] - 'a'] == 0){
                hash[s[i] - 'a'] = i + 1;   //这里让i + 1方便计算(并且方便判断hash值, 因为我们使用的hash与0的比较)
            }
            else{
                res = max(res, i - hash[s[i] - 'a']);
            }
        }
        return res;
    }
};