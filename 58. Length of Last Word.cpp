class Solution {
public:
    int lengthOfLastWord(string s) {
        int i = s.length() - 1;
        while(s[i] == ' ') {
            i--;
        }
        int end = i;
        while(i--) {
            if(s[i] == ' ') {
                break;
            }
        }
        return end - i;
    }
};