class Solution {
public:
    const string letterMap[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    vector<string> result;
    string s;

    void backtrack(const string& digits, int index) {
        if(index == digits.size()) {
            result.push_back(s);
            return;
        }
        int digit = digits[index] - '0';
        string letters = letterMap[digit];
        for(int i = 0; i < letters.size(); i++) {
            s.push_back(letters[i]);
            backtrack(digits, index + 1);
            s.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        s.clear();
        result.clear();
        if(digits.size() == 0) {
            return result;
        }
        backtrack(digits, 0);
        return result;
    }
};