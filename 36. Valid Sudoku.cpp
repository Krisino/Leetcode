class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int row[9][10] = {0},col[9][10] = {0},box[9][10] = {0};
        for(int i = 0; i < 9; i ++){
            for(int j = 0; j < 9; j ++){
                if(board[i][j] ==  '.') continue;
                int block = j/3+3*(i/3);
                int num = board[i][j] - '0';
                if(row[i][num]||col[j][num]||box[block][num]){
                    return false;
                }else{
                    row[i][num] = 1;
                    col[j][num] = 1;
                    box[block][num] = 1;
                }
            }
        }
        return true;
    }
};