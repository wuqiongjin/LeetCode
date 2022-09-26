class Solution {
public:
    //0 = 2 * 5
    //我们只需要统计出有多少个2和多少个5即可
    int trailingZeroes(int n) {
        int v2 = 0, v5 = 0;
        for(int i = n; i >= 2; --i)
        {
            int tmp = i;
            while(tmp % 2 == 0)
            {
                v2++;
                tmp /= 2;
            }
            tmp = i;
            while(tmp % 5 == 0)
            {
                v5++;
                tmp /= 5;
            }
        }

        return min(v2, v5);
    }
};