class Solution {
public:
    string addBinary(string a, string b) 
    {
        string ans;

        int i = a.size() - 1, j = b.size() - 1;
        int takeOver = 0;       
        for(; i >= 0 || j >= 0; --i, --j)
        {
            int val = 0;
            //考虑到 a和b的长度不一样时，必然会有1个先遍历完。
            //所以需要分别相加
            if(i < 0)
                val = b[j] - '0' + takeOver;
            else if(j < 0)
                val = a[i] - '0' + takeOver;
            else 
                val = a[i] - '0' + b[j] - '0' + takeOver;
            takeOver = val / 2;
            val %= 2;
            ans += val + '0';
        }

        //当takeOver还不为0的时候，需要额外补一位
        if(takeOver)
        {
            ans += takeOver + '0';
        }
        
        reverse(ans.begin(), ans.end());
        return ans;
    }
};