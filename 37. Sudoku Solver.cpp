class Solution {
public:
    bool isValid(int row, int col, char val, vector<vector<char>>& board) {
        for(int i = 0; i < 9; i++) {
            if(board[row][i] == val) {
                return false;
            }
            if(board[i][col] == val) {
                return false;
            }
        }
        int startRow = (row / 3) * 3;
        int startCol = (col / 3) * 3;
        for(int i = startRow; i < startRow + 3; i++) {
            for(int j = startCol; j < startCol + 3; j++) {
                if(board[i][j] == val) {
                    return false;
                }
            }
        }
        return true;
    }

    bool backtrack(vector<vector<char>>& board) {
        for(int i = 0; i < board.size(); i++) {
            for(int j = 0; j < board[0].size(); j++) {
                if(board[i][j] != '.') {
                    continue;
                }
                for(char c = '1'; c <= '9'; c++) {
                    if(isValid(i, j, c, board)) {
                        board[i][j] = c;
                        if(backtrack(board)) {
                            return true;
                        }
                        board[i][j] = '.';
                    }
                }
                return false;
            }
        }
        return true;
    }

    void solveSudoku(vector<vector<char>>& board) {
        backtrack(board);
    }
};