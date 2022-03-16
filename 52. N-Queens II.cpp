class Solution {
public:
    int count;
    bool isValid(vector<vector<int> > & chessboard, int r, int c, int n) {
        // check col
        for(int i = 0; i <= r; i++) {
            if(chessboard[i][c] != 0) {
                return false;
            }
        }
        // check row
        for(int i = 0; i <= c; i++) {
            if(chessboard[r][i] != 0) {
                return false;
            }
        }
        // check 45 degree direction
        for(int i = r, j = c; i >= 0 && j < n; i--, j++) {
            if(chessboard[i][j] != 0) {
                return false;
            }
        }
        // check 135 degree direction
        for(int i = r, j = c; i >= 0 && j >= 0; i--, j--) {
            if(chessboard[i][j] != 0) {
                return false;
            }
        }
        return true;
    }

    void traverse(vector<vector<int> > & chessboard, int row, int n) {
        if(row == n) {
            count++;
            return;
        }
        for(int i = 0; i < n; i++) {
            if(isValid(chessboard, row, i, n)) {
                chessboard[row][i] = 1;
                traverse(chessboard, row + 1, n);
                chessboard[row][i] = 0;
            }
        }
    }
    int totalNQueens(int n) {
        count = 0;
        vector<vector<int>> chessboard(n, vector<int>(n, 0));
        traverse(chessboard, 0, n);
        return count;
    }
};