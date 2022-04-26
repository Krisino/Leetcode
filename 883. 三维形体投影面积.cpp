class Solution {
public:
    int projectionArea(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> x(n, 0);
        vector<int> y(n, 0);
        int area = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] != 0) {
                    area++;
                }
                if(grid[i][j] > x[i]) {
                    x[i] = grid[i][j];
                }
                if(grid[i][j] > y[j]) {
                    y[j] = grid[i][j];
                }
            }
        }
        for(int i = 0; i < n; i++) {
            if(x[i] != 0) {
                area += x[i];
            }
            if(x[i] != 0) {
                area += y[i];
            }
        }
        return area;
    }
};