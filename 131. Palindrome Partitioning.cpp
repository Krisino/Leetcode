class Solution {
public:
    vector<vector<string>> result;
    vector<string> path;

    bool isPalindrome(const string& str, int start, int end) {
        for(int i = start, j = end; i <= j; i++, j--) {
            if(str[i] != str[j]) {
                return false;
            }
        }
        return true;
    }

    void backtrack(const string& str, int startIndex) {
        if(startIndex >= str.size()) {
            result.push_back(path);
            return;
        }
        for(int i = startIndex; i < str.size(); i++) {
            if(isPalindrome(str, startIndex, i)) {
                string s = str.substr(startIndex, i - startIndex + 1);
                path.push_back(s);
            } else {
                continue;
            }
            backtrack(str, i + 1);
            path.pop_back();
        }
    }

    vector<vector<string>> partition(string s) {
        result.clear();
        path.clear();
        backtrack(s, 0);
        return result;
    }
};