class NumMatrix {
public:
    vector<vector<int>> prefix_sum;
    NumMatrix(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        prefix_sum = vector<vector<int>>(row + 1, vector<int>(col + 1, 0));
        for(int i = 1; i <= row; i++) {
            for(int j = 1; j <= col; j++) {
                prefix_sum[i][j] = prefix_sum[i - 1][j]
                + prefix_sum[i][j - 1]
                - prefix_sum[i - 1][j - 1]
                + matrix[i - 1][j - 1];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        row1 += 1;
        col1 += 1;
        row2 += 1;
        col2 += 1;
        return prefix_sum[row2][col2]
        - prefix_sum[row1 - 1][col2]
        - prefix_sum[row2][col1 - 1]
        + prefix_sum[row1 - 1][col1 - 1];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */