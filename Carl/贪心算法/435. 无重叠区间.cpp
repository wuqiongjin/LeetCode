class Solution {
public:
    //贪心算法
    //本题要求移出区间的最小数量 --> 本质就是找出不重叠区间的最大值, 然后用总大小减去这个最大值
    //如何求不重叠区间的最大值呢?
    //我们可以按照右端点进行排序
    //右端点排序后, 我们从"左 向 右"遍历，判断右端点与下一个区间的左端点是否重合
    //如果不重合，那么更新右端点的值
    //如果重合, 那么就不管这个区间了(证明它需要被移出掉)
    //我们如何保证的整体是最优解呢? 因为我们每次都是选取了最小的右端点, 因此最终一定能够合并数量最多的区间
    int eraseOverlapIntervals(vector<vector<int>>& intervals) 
    {
        //按照区间右端点进行排序
        sort(intervals.begin(), intervals.end(), [](vector<int>& x, vector<int>& y){
            return x[1] < y[1];
        });

        int right = intervals[0][1];
        int count = 1;  //第一个区间作为必选
        for(int i = 1; i < intervals.size(); ++i)
        {
            if(intervals[i][0] >= right){//当前区间的左端点 >= 最大右端点 (说明该区间不重合, 应该更新右端点)
                right = intervals[i][1];
                ++count;
            }
        }
        return intervals.size() - count;
    }
};