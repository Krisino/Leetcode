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
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size() < n - 1) {
            return -1;
        }
        DisjointSet ds(n);
        for(int i = 0; i < connections.size(); i++) {
            ds.merge(connections[i][0], connections[i][1]);
        }
        return ds.size - 1;
    }
};