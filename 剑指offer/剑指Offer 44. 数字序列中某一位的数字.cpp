class Solution {
public:
    int findNthDigit(int n) {
        int base = 1;
        int weight = 9;
        while(n > (long)base * weight)
        {
            n -= base * weight;
            ++base;
            weight *= 10;
        }
        //对于序号300, 300 - 189(9 + 90 * 2) = 111
        //111 对应 base = 3, weight = 900
        //由于三位数的第一个是100, 直接用111/3是计算不正确的, 所以需要--n
        --n;    //不好理解...
        int res = (int)pow(10, base - 1) + (n / base);  // n / base算它在第几位数
        int index = n % base;
        return to_string(res)[index] - '0';
    }
};