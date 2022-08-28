//1. 通过逻辑判断让运算短路 (达到if判断的作用)
class Solution {
public:
    int sumNums(int n) {
        bool x = n > 0 && sumNums(n - 1);
        res += n;
        return res;
    }
    int res = 0;
};


//2. 利用求和公式,(1 + n) * n - 1 / 2
class Solution {
public:
    int sumNums(int n) {
        return sizeof(char[n][n + 1]) >> 1;
    }
};
//(1 + n) * n / 2