class Solution {
public:
    bool reachBorder(vector<vector<int>>& maze, int r, int c) {
        if(r >= 0 && c >= 0 && r < maze.size() && c < maze[0].size() && maze[r][c] == 0) {
            return false;
        }
        return true;
    }

    bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        vector<int> dx = {0, 0, 1, -1};
        vector<int> dy = {1, -1, 0, 0};
        int n = maze.size();
        int m = maze[0].size();
        vector<vector<bool> > visited(n, vector<bool>(m, false));
        queue<pair<int, int> > que;
        que.push(make_pair(start[0], start[1]));
        visited[start[0]][start[1]] = true;
        while(!que.empty()) {
            int x = que.front().first;
            int y = que.front().second;
            que.pop();
            if(x == destination[0] && y == destination[1]) {
                return true;
            }
            for(int i = 0; i < 4; i++) {
                int nx = x;
                int ny = y;
                while(!reachBorder(maze, nx + dx[i], ny + dy[i])) {
                    nx += dx[i];
                    ny += dy[i];
                }
                if(!visited[nx][ny]) {
                    que.push(make_pair(nx, ny));
                    visited[nx][ny] = true;
                } 
            }
        }
        return false;
    }
};