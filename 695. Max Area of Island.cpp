class Solution {
public:
    int curArea;

    bool inArea(vector<vector<int>>& grid, int r, int c) {
        if(r < 0 || c < 0 || r >= grid.size() || c >= grid[0] .size()) {
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
        curArea++;
        dfs(grid, r - 1, c);
        dfs(grid, r + 1, c);
        dfs(grid, r, c - 1);
        dfs(grid, r, c + 1);
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxArea = 0;
        if(grid.size() == 0) {
            return maxArea;
        }
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
                if(grid[i][j] == 1) {
                    curArea = 0;
                    dfs(grid, i, j);
                    maxArea = max(maxArea, curArea);
                }
            }
        }
        return maxArea;
    }
};