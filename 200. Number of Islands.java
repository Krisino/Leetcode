class Solution {
    void dfs(char[][] grid, int r, int c) {
        if(grid[r][c] != '1') {
            return;
        }
        grid[r][c] = '2';
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
            dfs(grid, r, c + 1);
        }
    }
    public int numIslands(char[][] grid) {
        int result = 0;
        for(int i = 0; i < grid.length; i++) {
            for(int j = 0; j < grid[0].length; j++) {
                if(grid[i][j] == '1') {
                    dfs(grid, i, j);
                    result++;
                }
            }
        }
        return result;
    }
}