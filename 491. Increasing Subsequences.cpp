class Solution {
public:
    vector<vector<int>> result;
    vector<int>path;

    void backtrack(vector<int>& nums, int startIndex) {
        if(path.size() >= 2) {
            result.push_back(path);
        }
        unordered_set<int> used;
        for(int i = startIndex; i < nums.size(); i++) {
            if((!path.empty() && nums[i] < path.back()) || used.find(nums[i]) != used.end()) {
                continue;
            }
            used.insert(nums[i]);
            path.push_back(nums[i]);
            backtrack(nums, i + 1);
            path.pop_back();
        }
    }

    vector<vector<int>> findSubsequences(vector<int>& nums) {
        result.clear();
        path.clear();
        backtrack(nums, 0);
        return result;
    }
};