class Solution {
public:

    //按层遍历，一层一层的遍历
    vector<int> spiralOrder(vector<vector<int>>& matrix) 
    {
        vector<int> ans;
        int ROW = matrix.size(), COL = matrix[0].size();
        int top = 0, left = 0, bottom = ROW - 1, right = COL - 1;
        //将矩阵的四个顶点的坐标确定下来。
        //左上(top,left)、右上(top, right)、左下(bottom, left)、右下(bottom, right)
        int row = 0, col = 0;
        while(top <= bottom && left <= right)
        {
            for(row = left; row <= right; row++)
            {
                ans.push_back(matrix[top][row]);
            }
            ++top;
            
            for(col = top; col <= bottom; ++col)
            {
                ans.push_back(matrix[col][right]);
            }
            --right;

            //这里的判断是精髓
            //当进行到最后一行时，top > bottom了，但是此时 left <= right仍然满足
            //所以需要额外判断
            //如果进行到最后一列的话，也是同理。left > right，但是top <= bottom
            if(top <= bottom && left <= right)
            {
                for(row = right; row >= left; --row)
                {
                    ans.push_back(matrix[bottom][row]);
                }
                --bottom;

                for(col = bottom; col >= top; --col)
                {
                    ans.push_back(matrix[col][left]);
                }
                ++left;
            }

        }
        return ans;
    }
};