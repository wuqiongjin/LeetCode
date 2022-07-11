class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int rows[9][9] = { 0 };
        int col[9][9] = { 0 };
        int subbox[3][3][9] = { 0 };

        for(int i = 0; i < 9; ++i){
            for(int j = 0; j < 9; ++j){
                if(board[i][j] == '.'){
                    continue;
                }
                int num = board[i][j] - '0' - 1;
                rows[i][num]++;
                col[j][num]++;
                subbox[i / 3][j / 3][num]++;
                if(rows[i][num] > 1 || col[j][num] > 1 || subbox[i / 3][j / 3][num] > 1){
                    return false;
                }
            }
        }
        return true;
    }
};