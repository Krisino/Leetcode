class Solution {
public:
    bool reachBorder;
    bool inArea(vector<vector<int>>& grid, int r, int c) {
        if(r < 0 || r >= grid.size() || c < 0 || c >= grid[0].size()) {
            return false;
        }
        return true;
    }

    void dfs(vector<vector<int>>& grid, int r, int c) {
        if(!inArea(grid, r, c)) {
            reachBorder = true;
            return;
        }
        if(grid[r][c] != 0) {
            return;
        }
        grid[r][c] = 2;
        dfs(grid, r - 1, c);
        dfs(grid, r + 1, c);
        dfs(grid, r, c - 1);
        dfs(grid, r, c + 1);
    }

    int closedIsland(vector<vector<int>>& grid) {
        int result = 0;
        if(grid.size() == 0) {
            return result;
        }
        for(int i = 1; i < grid.size() - 1; i++) {
            for(int j = 1; j < grid[0].size() - 1; j++) {
                if(grid[i][j] == 0) {
                        reachBorder = false;
                        dfs(grid, i, j);
                        if(!reachBorder) {
                            result++;
                        }
                }
            }
        }
        return result;
    }
};