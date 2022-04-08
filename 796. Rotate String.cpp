class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.size() != goal.size()) {
            return false;
        }
        string newGoal = goal + goal;
        int i = 0, j;
        while(i < goal.size()) {
            j = 0;
            while(s[j] == newGoal[i + j]) {
                j++;
            }
            if(j == s.size()) {
                return true;
            } else {
                i++;
            }
        }
        return false;
    }
};