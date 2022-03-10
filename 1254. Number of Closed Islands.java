class Solution {
    boolean reachBorder;
    boolean inArea(int[][] grid, int r, int c) {
        if(r < 0 || c < 0 || r >= grid.length || c >= grid[0].length) {
            reachBorder = true;
            return false;
        }
        return true;
    }

    void dfs(int[][] grid, int r, int c) {
        if(!inArea(grid, r, c)) {
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
    public int closedIsland(int[][] grid) {
        int result = 0;
        for(int i = 1; i < grid.length - 1; i++) {
            for(int j = 1; j < grid[0].length - 1; j++) {
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
}