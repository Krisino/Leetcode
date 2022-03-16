// class Solution {
// public:
    //  DFS
    // void dfs(vector<vector<int>>& isConnected, vector<bool>& visited, int i, int n) {
    //     visited[i] = true;
    //     for(int j = 0; j < n; j++) {
    //         if(isConnected[i][j] == 1 && !visited[j]) {
    //             dfs(isConnected, visited, j, n);
    //         }
    //     }
    // }

    // int findCircleNum(vector<vector<int>>& isConnected) {
    //     int result = 0;
    //     int n = isConnected.size();
    //     vector<bool> visited(n, false);
    //     for(int i = 0; i < n; i++) {
    //         if(!visited[i]) {
    //             result++;
    //             dfs(isConnected, visited, i, n);
    //         }
    //     }
    //     return result;
    // }

    // BFS
    // int findCircleNum(vector<vector<int>>& isConnected) {
    //     int result = 0;
    //     int n = isConnected.size();
    //     vector<bool> visited(n, false);
    //     queue<int> que;
    //     for(int i = 0; i < n; i++) {
    //         if(!visited[i]) {
    //             result++;
    //             que.push(i);
    //             visited[i] = true;
    //             while(!que.empty()) {
    //                 int index = que.front();
    //                 que.pop();
    //                 for(int j = 0; j < n; j++) {
    //                     if(isConnected[index][j] == 1 && !visited[j]) {
    //                         visited[j] = true;
    //                         que.push(j);
    //                     }
    //                 }
    //             }
    //         }
    //     }
    //     return result;
    // }
// };

// Disjoint Set
class DisjointSet {
public:
    vector<int> ds;
    int size;

    DisjointSet(int n) {
        ds.resize(n);
        for(int i = 0; i < n; i++) {
            ds[i] = i;
        }
        size = n;
    }

    int find(int x) {
        if(ds[x] == x) {
            return x;
        } else {
            return find(ds[x]);
        }
    }

    void merge(int i, int j) {
        if(find(i) != find(j)) {
            ds[find(i)] = find(j);
            size--;
        }
    }
};

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        DisjointSet ds(n);
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(isConnected[i][j] == 1) {
                    ds.merge(i, j);
                }
            }
        }
        return ds.size;
    }
};
