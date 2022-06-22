class Solution {
public:
    //1. 暴力解法 O(N^2)
    // //这些写会超时的... 题里给了一个条件"如果存在解, 则保证它是唯一的"
    // int canCompleteCircuit(vector<int>& gas, vector<int>& cost) 
    // {
    //     // vector<int> netgas(gas.size());
    //     // for(int i = 0; i < gas.size(); ++i)
    //     // {
    //     //     netgas[i] = gas[i] - cost[i];
    //     // }

    //     map<int,int, greater<int>> mii;
    //     int sz = gas.size();
    //     for(int i = 0; i < gas.size(); ++i)
    //     {
    //         int maxGas = 0;
    //         bool flag = false;
    //         for(int j = i, count = 0; count < gas.size(); ++count)
    //         {
    //             maxGas += gas[j] - cost[j];
    //             if(maxGas < 0){
    //                 flag = true;
    //                 break;
    //             }
    //             ++j;
    //             j %= gas.size();
    //         }
    //         //可以放入mii的结果集
    //         if(!flag){
    //             mii.emplace(maxGas, i);
    //         }
    //     }

    //     if(mii.empty()) //说明没有任何一个索引能够达成条件
    //         return -1;

    //     return mii.begin()->second; //返回第一个元素的索引值(降序排列的)
    // }

    //2. 贪心算法 O(N)
    //关键思路"一旦当前的curSumGas值小于0, 回溯到i + 1位置"
    //假设 netgas[-1, 2, -1, -3, 4, 5]
    //最开始设start为0索引, i值为0; 由于-1 < 0, 回溯到 i + 1位置, 即start从1索引开始
    //       start从1索引, i=1, curSumGas=2 > 0, 继续; 
    //                     i=2, curSumGas=1 > 0, 继续;
    //                     i=3, curSumGas=-2 < 0, 回溯到i+1位置, 即start从4索引开始
    //       start从4索引, i=4, curSumGas=4 > 0, 继续;
    //                     i=5, curSumGas=9 > 0, 继续;
    //                      ...
    //              4索引满足条件 √
    //问题:为什么1索引不行后, 直接跳到了4索引处? 1索引不行, 你跳到2、3索引也不行! 只会让值更负...
    //        因为1索引之所以能往后走, 证明1索引的值肯定>0, 你跳到2、3索引, 你少了一个1索引的正值, 只会更负数
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) 
    {
        int startIndex = 0; //起始索引
        int curSumGas = 0;  //当前的净汽油量
        int totalSumGas = 0;    //总共净汽油量
        for(int i = 0; i < gas.size(); ++i)
        {
            curSumGas += gas[i] - cost[i];
            totalSumGas += gas[i] - cost[i];
            if(curSumGas < 0){
                startIndex = i + 1;
                curSumGas = 0;
            }
        }

        if(totalSumGas < 0)
            return -1;
        return startIndex;
    }

    //3. 另辟蹊径的巧妙思路 O(N)
    //定义一个minSumGas, 先遍历一遍,记录整个过程的油量最低点, 然后逆序遍历, 找到能够填平负数的那一个索引位置
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) 
    {
        int minSumGas = INT_MAX;
        int totalSumGas = 0;
        for(int i = 0; i < gas.size(); ++i)
        {
            totalSumGas += gas[i] - cost[i];
            if(totalSumGas < minSumGas){
                minSumGas = totalSumGas;
            }
        }

        if(totalSumGas < 0) return -1;
        if(minSumGas >= 0)  return 0;

        for(int i = gas.size() - 1; i >= 0; --i)
        {
            minSumGas += gas[i] - cost[i];
            if(minSumGas >= 0){
                return i;
            }
        }
        return -1;
    }
};