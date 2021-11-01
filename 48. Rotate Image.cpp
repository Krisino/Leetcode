class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n, row, col;
        n = matrix[0].size();
        if(n % 2 == 1){
            row = (n - 1) / 2;
            col = (n + 1) / 2;
        } else {
            row = n / 2;
            col = n / 2;
        }
        for(int i = 0; i < row; i++) {
            for(int j = 0; j < col; j++) {
                int tmp = matrix[i][j];
                matrix[i][j] = matrix[n - 1 - j][i];
                matrix[n - 1 - j][i] = matrix[n - 1 - i][n - 1 - j];
                matrix[n - 1 - i][n - 1 - j] = matrix[j][n - 1 - i];
                matrix[j][n - 1 - i] = tmp;
            }
        }
    }
};