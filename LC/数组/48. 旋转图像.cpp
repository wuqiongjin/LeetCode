class Solution {
public:
    void rotate(vector<vector<int>>& matrix) 
    {
        int n = matrix.size();
        //考虑到奇和偶的矩阵
        for(int row = 0; row < (n + 1) / 2; ++row)
        {
            for(int col = 0; col < n / 2; ++col)
            {
                //这几步得自己一步一步推出来
                int tmp = matrix[row][col];
                matrix[row][col] = matrix[n - col - 1][row];
                matrix[n - col - 1][row] = matrix[n - 1 - row][n - 1 - col];
                matrix[n - 1 - row][n - 1 - col] = matrix[col][n - 1 - row];
                matrix[col][n - 1 - row] = tmp;
            }
        }
    }
};