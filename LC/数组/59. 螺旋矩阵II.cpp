class Solution {
public:
    vector<vector<int>> generateMatrix(int n) 
    {
        int ROW = n, COL = n;
        //vector的构造初始化
        vector<vector<int>> ans(ROW, vector<int>(COL));
        int top = 0, left = 0, bottom = ROW - 1, right = COL - 1;
        int row = 0, col = 0;
        int index = 0;
        while(top <= bottom && left <= right)
        {
            for(row = left; row <= right; ++row)
            {
                ans[top][row] = ++index;
            }
            ++top;

            for(col = top; col <= bottom; ++col)
            {
                ans[col][right] = ++index;
            }
            --right;

            //这里不需要像螺旋矩阵I中的那样做判断了。因为这里是正方形的矩阵
            //所以不会出现left <= right但是bottom > top的情况 (自己画图看看)
            for(row = right; row >= left; --row)
            {
                ans[bottom][row] = ++index;
            }
            --bottom;

            for(col = bottom; col >= top; --col)
            {
                ans[col][left] = ++index;
            }
            ++left;

        }
        return ans;
    }
};