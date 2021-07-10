class Solution {
public:
    //整体思路：
    //首先根据区间的左边界进行排序
    //创建二维数组ans，用来存放合并后的区间
    //start表示判断区间的起始下标，end是正要进行比较的下标，curlen是可以合并的区间的终止下标
    //maxborder就是合并区间的右边界的最大值了
    vector<vector<int>> merge(vector<vector<int>>& intervals) 
    {
        int sz = intervals.size();
        if(sz == 1)
            return intervals;

        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;
        
        int start = 0, end = 1, curlen = 0;
        
        while(end <= sz)
        {
            //maxborder确定重叠区间的有边界
            int maxborder = intervals[curlen][1];
            //每次要进行判断，即，最大的右边界的值是否>=新区间的左边界。如果大于等于就是重叠区间
            while(end < sz && maxborder >= intervals[end][0])
            {
                curlen = end++;
                maxborder = max(maxborder, intervals[curlen][1]);
                // ++end;
            }

            ans.push_back(vector<int>{intervals[start][0], maxborder});
            ++curlen;
            start = curlen;
            ++end;
        }
        return ans;
    }
};