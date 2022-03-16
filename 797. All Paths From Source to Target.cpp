class Solution {
public:
    vector<vector<int>> result;
    vector<int> path;

    void traverse(vector<vector<int>>& graph, int index, int n) {
        if(path.back() == n - 1) {
            result.push_back(path);
            return;
        }
        for(int i = 0; i < graph[index].size(); i++) {
            path.push_back(graph[index][i]);
            traverse(graph, graph[index][i], n);
            path.pop_back();
        }
    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        result.clear();
        path.clear();
        int n = graph.size();
        path.push_back(0);
        traverse(graph, 0, n);
        return result;
    }
};