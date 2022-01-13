class Solution {
public:
    // KMP Algorithm 构造前缀表
    void getNext(int * next, const string & s) {
        int j = -1;
        next[0] = j;

        for(int i = 1; i < s.length(); i++) {
            while(j >= 0 && s[i] != s[j + 1]) {
                j = next[j];
            }
            if(s[i] == s[j + 1]) {
                j++;
            }
            next[i] = j;
        }
    }
    bool repeatedSubstringPattern(string s) {
        int n = s.length();
        if(n == 0) {
            return false;
        }

        int next[n];
        getNext(next, s);

        // 当 s 由重复子字符串重复构成时，len(s) - (next[len(s) - 1] + 1)为重复子字符串长度
        // 当这个长度能被 len(s) 整除时，说明是由该子字符串重复组成
        if(next[n - 1] != -1 && n % (n - (next[n - 1] + 1)) == 0) {
            return true;
        }
        
        return false;
    }
};