class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) 
    {
        int minPrice = prices[0];
        int profit = 0;

        for(int i = 1; i < prices.size(); ++i)
        {
            //更新最低价格
            if(prices[i] < minPrice){
                minPrice = prices[i];
            }

            //有利润可得(不在这两个if条件判断中的就是亏损的卖出)
            if(prices[i] > minPrice + fee){
                profit += prices[i] - minPrice - fee;
                minPrice = prices[i] - fee;
//1.因为明天的股票价格可能比今天还高, 所以这里我们并不是真的把股票在这一天卖出了. 
//结合当前的if语句块的条件判断"prices[i] > minPrice + fee", 明天的股票价格必须>今天的股票价格, 此时在明天才会进入到这个if判断中。
//因此我们需要判断今天和明天的股票价格大小. 所以这里我们让minProce = prices[i] - fee, 带入到if判断中就是"prices[i] > prices[i]",
//前面的那个是明天的股票价值, 后面的是今天的股票价值。

//在profit计算时, 我们算的也是净利润, 即便是明天真的卖出了, 那么profit +=的值是明天卖出相比今天卖出多获得的利润

//2.如果明天的股票价格比minPrice低, 那么此时就说明股票应该在今天卖出,
//此时我们会通过第一个if条件判断, 直接更新minPrice的值. 而profit的值就相当于已经加过了今天的股票利润了。
            }
        }
        return profit;
    }
};