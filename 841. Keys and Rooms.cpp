class Solution {
public:
    void dfs(vector<vector<int>>& rooms, vector<bool>& visited, int index) {
        if(visited[index] == true) {
            return;
        }
        visited[index] = true;
        for(int i = 0; i < rooms[index].size(); i++) {
            dfs(rooms, visited, rooms[index][i]);
        }
    }

    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<bool> visited(n, false);
        dfs(rooms, visited, 0);
        for(int i = 0; i < n; i++) {
            if(visited[i] != true) {
                return false;
            }
        }
        return true;
    }
};