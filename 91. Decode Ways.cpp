class Solution {
public:
    int numDecodings(string s) {
        if(s[0] == '0') {
            return 0;
        }
        int pre = 1;
        int cur = 1;
        for(int i = 1; i < s.size(); i++) {
            int temp = cur;
            if(s[i] == '0' && (s[i - 1] == '1' || s[i - 1] == '2')) {
                cur = pre;
            } else if (s[i] == '0' && s[i - 1] != '1' && s[i - 1] != '2') {
                return 0;
            } else if(s[i - 1] == '1') {
                cur = pre + cur;
            } else if(s[i - 1] == '2' && (s[i] >= '0' && s[i] <= '6')) {
                cur = pre + cur;
            }
            pre = temp;
        }
        return cur;
    }
};