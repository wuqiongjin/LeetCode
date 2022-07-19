//[已超时...TL]方法1: 暴力解法(枚举法)	时间: O(N * 根号N) 空间: O(1)
class Solution {
public:
    bool isPrime(int n){
        for(int i = 3; i <= sqrt(n); i += 2)
        {
            if(n % i == 0){
                return false;
            }
        }
        return true;
    }

    int countPrimes(int n) {
        if(n <= 2) return 0;    //这题最坑的一点是, 它求的是"小于 < n"的素数个数。即n=2, 小于2的素数个数为0...

        int cnt = 1;    //已经包含2了
        for(int i = 3; i < n; i += 2)   //i直接从素数3开始, 每次 += 2, 然后判断是否是素数
        {
            if(isPrime(i)){
                ++cnt;
            }
        }
        return cnt;
    }
};


//方法2: 埃氏筛 时间:O(N * loglogN)  空间:O(N)
class Solution {
public:
    const int MAX_NUM = 1e6 * 5;
    int countPrimes(int n) {
        static deque<bool> dq(MAX_NUM, true);   //不定义成静态的, 会超时的...
        //这里直接从2开始, 只需要存储到sqrt(n)即可
        for(int i = 2; i <= sqrt(n); ++i)
        {
            if(dq[i] == true){
                for(int j = i * i; j < n; j += i)   //j从i*i开始, 每次增加一倍i. 4 6 8 10 ...
                {                                                           // 9 12 15 18   //对于3而言,6是3的2倍，这个2倍则意味着它在2中出现过了
                    dq[j] = false;                                          // 16 20 24 28  //对于4而言,8是4的2倍，12是4的3倍，这些都在前面出现过了
                }                                                           // 25 30 35 40
            }
        }

        int cnt = 0;
        for(int i = 2; i < n; ++i)  //最终只需要找到dq[i]为true的即是素数
        {
            if(dq[i] == true){
                ++cnt;
            }
        }
        return cnt;
    }
};