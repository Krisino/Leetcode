class Solution {
public:
    vector<vector<int>> result;
    vector<int>path;

    void backtrack(vector<int>& nums, int startIndex) {
        if(path.size() >= 2) {
            result.push_back(path);
            return;
        }
        for(int i = startIndex; i < nums.size(); i++) {
            
        }
    }

    vector<vector<int>> findSubsequences(vector<int>& nums) {
        result.clear();
        path.clear();
        backtrack(nums, 0);
        return result;
    }
};