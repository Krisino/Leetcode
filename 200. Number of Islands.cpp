class Solution {
public:
    // // BFS
    // void bfs(vector<vector<char>>& grid, vector<int>& dx, vector<int>& dy, int r, int c) {
    //     queue<pair<int, int> > que;
    //     int n = grid.size();
    //     int m = grid[0].size();
    //     que.push(make_pair(r, c));
    //     grid[r][c] = '2';
    //     while(!que.empty()) {
    //         int x = que.front().first;
    //         int y = que.front().second;
    //         que.pop();
    //         for(int i = 0; i < 4; i++) {
    //             int nx = x + dx[i];
    //             int ny = y + dy[i];
    //             if(nx >= 0 && ny >= 0 && nx < n && ny < m && grid[nx][ny] == '1') {
    //                 que.push(make_pair(nx, ny));
    //                 grid[nx][ny] = '2';
    //             }
    //         }
    //     }
    // }

    // int numIslands(vector<vector<char>>& grid) {
    //     int result = 0;
    //     if(grid.size() == 0) {
    //         return result;
    //     }
    //     vector<int> dx = {0, 0, 1, -1};
    //     vector<int> dy = {1, -1, 0, 0};
    //     for(int i = 0; i < grid.size(); i++) {
    //         for(int j = 0; j < grid[0].size(); j++) {
    //             if(grid[i][j] == '1') {
    //                 bfs(grid, dx, dy, i, j);
    //                 result++;
    //             }
    //         }
    //     }
    //     return result;
    // }

    bool inArea(vector<vector<char>>& grid, int r, int c) {
        if(r < 0 || r >= grid.size() || c < 0 || c >= grid[0].size()) {
            return false;
        }
        return true;
    }
    void dfs(vector<vector<char>>& grid, int r, int c) {
        if(!inArea(grid, r, c)) {
            return;
        }
        if(grid[r][c] != '1') {
            return;
        }
        grid[r][c] = '2';
        dfs(grid, r - 1, c);
        dfs(grid, r + 1, c);
        dfs(grid, r, c - 1);
        dfs(grid, r, c + 1);
    }
    int numIslands(vector<vector<char>>& grid) {
        int result = 0;
        if(grid.size() == 0) {
            return result;
        }
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
                if(grid[i][j] == '1') {
                    dfs(grid, i, j);
                    result++;
                }
            }
        }
        return result;
    }
};