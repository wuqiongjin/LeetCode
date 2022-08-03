//1. 优先队列
class Solution {
public:
    int nthUglyNumber(int n) {
        priority_queue<long, vector<long>, greater<long>> pq;
        unordered_set<long> us;
        pq.push(1L);
        long cnt = 0, res = 0;
        us.insert(1);
        while(cnt < n)
        {
            long top = pq.top();
            ++cnt;
            res = top;
            pq.pop();
            if(!us.count(top * 2)){
                us.insert(top * 2);
                pq.push(top * 2);
            }
            if(!us.count(top * 3)){
                us.insert(top * 3);
                pq.push(top * 3);
            }
            if(!us.count(top * 5)){
                us.insert(top * 5);
                pq.push(top * 5);
            }
        }
        return res;
    }
};


//2. dp
class Solution {
public:
    //动态规划:
    //思路: 先排序再存入数据
    //我们借助3个指针变量分别记录 一个丑数对应的 衍生出来的3个丑数
    //dp[i]每次只取 2/3/5 倍中最小的那个, 这样就完成了排序
    //借助3个指针, 保证一个丑数的 2/3/5 倍一定都被存入过dp数组
    // 假设dp[0] = 1, p2 --> 2; p3 ---> 3 ; p5 ---> 5
    //     dp[1] =2, p2 ---> 4; p3 ---> 6 ; p5 ---> 10
    //由于dp[1]的p2的数值小于dp[0]的p5数值, 因此在实际存入dp数组时， 是先存入了 2、3、4，再存入了5
    int nthUglyNumber(int n) {
        vector<int> dp(n);
        int p2 = 0, p3 = 0, p5 = 0;
        dp[0] = 1;
        for(int i = 1; i < n; ++i)
        {
            dp[i] = min({2 * dp[p2], 3 * dp[p3], 5 * dp[p5]});
            if(dp[i] == 2 * dp[p2]) ++p2;
            if(dp[i] == 3 * dp[p3]) ++p3;
            if(dp[i] == 5 * dp[p5]) ++p5;
        }
        return dp[n - 1];
    }
};