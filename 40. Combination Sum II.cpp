class Solution {
public:
    vector<vector<int>> result;
    vector<int> path;

    void backtrack(vector<int>& candidates, int target, int sum, int startIndex) {
        if(sum == target) {
                result.push_back(path);
                return;
            }
        for(int i = startIndex; i < candidates.size() && sum + candidates[i] <= target; i++) {
            if(i > startIndex && candidates[i] == candidates[i - 1]) {
                continue;
            }
            path.push_back(candidates[i]);
            sum += candidates[i];
            backtrack(candidates, target, sum, i + 1);
            sum -= candidates[i];
            path.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        result.clear();
        path.clear();
        sort(candidates.begin(), candidates.end());
        backtrack(candidates, target, 0, 0);
        return result;
    }
};