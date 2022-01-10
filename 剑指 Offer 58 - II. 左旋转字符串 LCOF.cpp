class Solution {
public:
    string reverseLeftWords(string s, int n) {
        int size = s.size();
        // 翻转 0~n 区间的子串
        reverse(s.begin(), s.begin() + n);
        // 翻转后 n~end 区间的子串
        reverse(s.begin() + n, s.end());
        // 翻转整个字符串
        reverse(s.begin(), s.end());
        return s;
    }
};