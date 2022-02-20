class Solution {
public:
    vector<string> result;

    void backtrack(int left, int right, string path) {
        if(left == 0 && right == 0) {
            result.push_back(path);
            return;
        }
        if(left > right) {
            return;
        }
        if(left > 0){
            backtrack(left - 1, right, path + "(");
        }
        if(right > 0){
            backtrack(left, right - 1, path + ")");
        }
    }

    vector<string> generateParenthesis(int n) {
        result.clear();
        backtrack(n, n, "");
        return result;
    }
};