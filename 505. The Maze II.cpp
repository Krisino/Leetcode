class Solution {
public:
    bool reachBorder(vector<vector<int>>& maze, int r, int c) {
        if(r >= 0 && c >= 0 && r < maze.size() && c < maze[0].size() && maze[r][c] == 0) {
            return false;
        }
        return true;
    }

    int shortestDistance(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        vector<int> dx = {0, 0, 1, -1};
        vector<int> dy = {1, -1, 0, 0};
        int n = maze.size();
        int m = maze[0].size();
        vector<vector<int> > distance(n, vector<int>(m, INT_MAX));
        queue<pair<int, int>> que;
        que.push(make_pair(start[0], start[1]));
        distance[start[0]][start[1]] = 0;
        while(!que.empty()) {
            int x = que.front().first;
            int y = que.front().second;
            que.pop();
            for(int i = 0; i < 4; i++) {
                int nx = x;
                int ny = y;
                int nd = distance[x][y];
                while(!reachBorder(maze, nx + dx[i], ny + dy[i])) {
                    nx += dx[i];
                    ny += dy[i];
                    nd++;
                }
                if(nd < distance[nx][ny]) {
                    distance[nx][ny] = nd;
                    que.push(make_pair(nx, ny));
                } 
            }
        }
        return distance[destination[0]][destination[1]] == INT_MAX ? -1 : distance[destination[0]][destination[1]];
    }
};