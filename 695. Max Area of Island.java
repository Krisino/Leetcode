class Solution {
    int curArea;

    void dfs(int[][] grid, int r, int c) {
        if(grid[r][c] != 1) {
            return;
        }
        grid[r][c] = 2;
        curArea++;
        if(r - 1 >= 0) {
            dfs(grid, r - 1, c);
        }
        if(r + 1 < grid.length) {
            dfs(grid, r + 1, c);
        }
        if(c - 1 >= 0) {
            dfs(grid, r, c - 1);
        }
        if(c + 1 < grid[0].length) {
            dfs(grid, r ,c + 1);
        }
    }
    public int maxAreaOfIsland(int[][] grid) {
        int maxArea = 0;
        for(int i = 0; i < grid.length; i++) {
            for(int j = 0; j < grid[0].length; j++) {
                if(grid[i][j] == 1) {
                    curArea = 0;
                    dfs(grid, i, j);
                    if(curArea > maxArea) {
                        maxArea = curArea;
                    }
                }
            }
        }
        return maxArea;
    }
}