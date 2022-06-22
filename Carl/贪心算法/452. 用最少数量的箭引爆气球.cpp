class Solution {
public:
    //贪心算法
    //只要一箭能够射到的气球数最多, 用的箭的数量就最少
    //我们首先需要排序
    //其次, 判断每个气球右边界与下一个气球的左边界. 
    //如果右边界 < 左边界, 说明不重合, 需要额外1个箭
    //如果重合, 则取这两个气球的最小右边界
    int findMinArrowShots(vector<vector<int>>& points) 
    {
        if(points.size() == 0)  return 0;
        sort(points.begin(), points.end(), [](vector<int>& x, vector<int>& y){
            if(x[0] == y[0])    return x[1] < y[1];
            return x[0] < y[0];
        });

        // int res = 0;
        // int i = 0;
        // while(i < points.size())
        // {
        //     int leftBorder = points[i][0];
        //     int rightBorder = points[i][1];
        //     ++i;
        //     while(i < points.size() && leftBorder <= points[i][0] && rightBorder >= points[i][0])
        //     {
        //         leftBorder = max(leftBorder, points[i][0]);
        //         rightBorder = min(rightBorder, points[i][1]);
        //         ++i;
        //     }
        //     ++res;
        // }

        int res = 1;    //至少需要1根箭
        //i从1开始, 与前面的进行判断
        for(int i = 1; i < points.size(); ++i)
        {
            //i与i-1没有任何部分重合
            if(points[i][0] > points[i - 1][1]){
                ++res;
            }
            else{//i和i-1重合一部分，选取重合部分的最小右边界(方便一下次循环进行判断)
                points[i][1] = min(points[i - 1][1], points[i][1]);
            }
        }

        return res;
    }
};