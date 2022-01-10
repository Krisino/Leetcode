class Solution {
public:
    string reverseStr(string s, int k) {
        int n = s.length();
        // 每次移动 2k 个距离
        for(int i = 0; i < n; i += 2 * k) {
            // 若存在前 k 个字符
            if(i + k <= n) {
                reverse(s.begin() + i, s.begin() + i + k);
            } else {
                // 不存在前 k 个，则反转当前位置到末尾位置
                reverse(s.begin() + i, s.end());
            }
        }
        return s;
    }
};