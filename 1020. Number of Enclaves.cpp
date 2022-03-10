class Solution {
public:
    bool reachBorder;
    int area;

    bool inArea(vector<vector<int>>& grid, int r, int c) {
        if(r < 0 || c < 0 || r >= grid.size() || c >= grid[0].size()) {
            reachBorder = true;
            return false;
        }
        return true;
    }

    void dfs(vector<vector<int>>& grid, int r, int c) {
        if(!inArea(grid, r, c)) {
            return;
        }
        if(grid[r][c] != 1) {
            return;
        }
        grid[r][c] = 2;
        area++;
        dfs(grid, r - 1, c);
        dfs(grid, r + 1, c);
        dfs(grid, r, c - 1);
        dfs(grid, r, c + 1);
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int result = 0;
        for(int i = 1; i < grid.size() - 1; i++) {
            for(int j = 1; j < grid[0]. size() - 1; j++) {
                if(grid[i][j] == 1) {
                    reachBorder = false;
                    area = 0;
                    dfs(grid, i, j);
                    if(!reachBorder) {
                        result += area;
                    }
                }
            }
        }
        return result;
    }
};