class Solution {
public:
    void build(vector<vector<int>>& mat, vector<vector<int>>& pre_sum) {
        for(int i = 1; i < pre_sum.size(); i++) {
            for(int j = 1; j < pre_sum[0].size(); j++) {
                pre_sum[i][j] = pre_sum[i - 1][j]
                + pre_sum[i][j - 1]
                - pre_sum[i - 1][j - 1]
                + mat[i - 1][j - 1];
            }
        }
    }

    int calc(vector<vector<int>>& pre_sum, int x1, int y1, int x2, int y2) {
        x1 += 1;
        y1 += 1;
        x2 += 1;
        y2 += 1;
        return pre_sum[x2][y2]
        - pre_sum[x1 - 1][y2]
        - pre_sum[x2][y1 - 1]
        + pre_sum[x1 - 1][y1 - 1];
    }

    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        int row = mat.size();
        int col = mat[0].size();
        vector<vector<int>> pre_sum(row + 1, vector<int>(col + 1, 0));
        build(mat, pre_sum);
        for(int i = 0; i < row; i++) {
            for(int j = 0; j < col; j++) {
                int x1, y1, x2, y2;
                if(i - k < 0) {
                    x1 = 0;
                } else {
                    x1 = i - k;
                }
                if(j - k < 0) {
                    y1 = 0; 
                } else {
                    y1 = j - k;
                }
                if(i + k >= row) {
                    x2 = row - 1;
                } else {
                    x2 = i + k;
                }
                if(j + k >= col) {
                    y2 = col - 1;
                } else {
                    y2 = j + k;
                }
                mat[i][j] = calc(pre_sum, x1, y1, x2, y2);
            }
        }
        return mat;
    }
};