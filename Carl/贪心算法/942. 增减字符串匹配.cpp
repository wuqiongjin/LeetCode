class Solution {
public:
    //贪心算法
    //适用条件:
    //最优子结构：规模较大的问题的解由规模较小的子问题的解组成，规模较大的问题的解只由其中一个规模较小的子问题的解决定；
    //无后效性：后面阶段的求解不会修改前面阶段已经计算好的结果；
    //贪心选择性质：从局部最优解可以得到全局最优解。
    //贪心的本质是选择每一阶段的局部最优，从而达到全局最优。
    vector<int> diStringMatch(string s) 
    {
        int len = s.size();
        int maxIndex = len;
        int minIndex = 0;

        vector<int> res(len + 1);

        int i = 0;
        while(i < s.size())
        {
            if(s[i] == 'I'){
                res[i] = minIndex;
                ++minIndex;
            }
            else{
                res[i] = maxIndex;
                --maxIndex;
            }
            ++i;
        }

        res[len] = maxIndex;
        
        return res;
    }
};