class Solution {
public:
    //本题不是简单地26进制
    //而是[1, 26]这个范围，所以可以通过每次手动让columnNumber--
    //从而得到[0, 25]这个属于26进制的范围
    string convertToTitle(int columnNumber) 
    {
        int ret = 0;
        string ans;
        while(columnNumber--)
        {
            ret = columnNumber % 26;
            ans += ret + 'A';
            columnNumber /= 26;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};