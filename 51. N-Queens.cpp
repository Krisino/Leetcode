class Solution {
public:
    vector<vector<string>> result;
    
    bool isValid(vector<string>& chessboard, int row, int col, int n) {
        for(int i = 0; i < row; i++) {
            if(chessboard[i][col] == 'Q') {
                return false;
            }
        }
        // 45 degree
        for(int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
            if(chessboard[i][j] == 'Q') {
                return false;
            }
        }
        // 135 degree
        for(int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
            if(chessboard[i][j] == 'Q') {
                return false;
            }
        }
        return true;
    }

    void backtrack(int n, int row, vector<string>& chessboard) {
        if(row == n) {
            result.push_back(chessboard);
            return;
        }
        for(int col = 0; col < n; col++) {
            if(isValid(chessboard, row, col, n)) {
                chessboard[row][col] = 'Q';
                backtrack(n, row + 1, chessboard);
                chessboard[row][col] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        result.clear();
        vector<string> chessboard(n, string(n, '.'));
        backtrack(n, 0, chessboard);
        return result;
    }
};