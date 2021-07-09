class Solution {
public:
    //双指针法
    //只需要每次让最短的那条边缩进，然后判断是否大于max
    //为什么只缩进最短的那条边?
    //因为对于那条边来说，不管另一条边如何变大，它们的最大值就是最短的那条边的高度*2条边的距离
    //所以另一条边如果缩进的话，它们的容积只会更少
    int maxArea(vector<int>& height) 
    {
        int start = 0, end = height.size() - 1;
        int max = min(height[start], height[end]) * end;
        while(start < end)
        {
            if(height[start] < height[end])
                ++start;
            else
                --end;
            int ret = min(height[start], height[end]) * (end - start);
            if(max < ret)
                max = ret;
        }
        return max;
    }
};