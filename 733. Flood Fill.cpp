class Solution {
public:
    // // BFS
    // vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
    //     if(image[sr][sc] == newColor) {
    //         return image;
    //     }
    //     int dx[] = {1, 0, 0, -1};
    //     int dy[] = {0, 1, -1, 0};
    //     int n = image.size();
    //     int m = image[0].size();
    //     int oldColor = image[sr][sc];
    //     queue<pair<int, int> > que;
    //     que.push(make_pair(sr, sc));
    //     image[sr][sc] = newColor;
    //     while(!que.empty()) {
    //         int x = que.front().first;
    //         int y = que.front().second;
    //         que.pop();
    //         for(int i = 0; i < 4; i++) {
    //             int newX = x + dx[i];
    //             int newY = y + dy[i];
    //             if(newX >= 0 && newY >= 0 && newX < n && newY < m) {
    //                 if(image[newX][newY] == oldColor) {
    //                     que.push(make_pair(newX, newY));
    //                     image[newX][newY] = newColor;
    //                 }
    //             }
    //         }
    //     }
    //     return image;
    // }

    void dfs(vector<vector<int>>& image, int sr, int sc, int oldColor, int newColor) {
        if(sr < 0 || sc < 0 || sr >= image.size() || sc >= image[0].size()) {
            return;
        }
        if(image[sr][sc] != oldColor) {
            return;
        }
        image[sr][sc] = newColor;
        dfs(image, sr - 1, sc, oldColor, newColor);
        dfs(image, sr + 1, sc, oldColor, newColor);
        dfs(image, sr, sc - 1, oldColor, newColor);
        dfs(image, sr, sc + 1, oldColor, newColor);
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int oldColor = image[sr][sc];
        if(oldColor == newColor) {
            return image;
        }
        dfs(image, sr, sc, oldColor, newColor);
        return image;
    }
};