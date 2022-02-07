class Solution {
public:
    vector<vector<int>> result;
    vector<int> path;

    void backtrack(int n, int k, int startIndex) {
        if(path.size() == k) {
            result.push_back(path);
            return;
        }
        for(int i = startIndex; i <= n - (k - path.size()) + 1; i++) {
            path.push_back(i);
            backtrack(n, k, i + 1);
            path.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        result.clear();
        path.clear();
        backtrack(n, k, 1);
        return result;
    }
};