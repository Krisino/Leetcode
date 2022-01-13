class Solution {
public:
    // 此方法将前缀表每个值 -1 得到新前缀表 next
    void getNext(int * next, const string & s) {
        int j = -1;
        next[0] = j;
        for(int i = 1; i < s.length(); i++) {
            // 失配情况
            while(j >=0 && s[i] != s[j + 1]) {
                // 关键步骤
                j = next[j];
            }
            // 成功匹配
            if(s[i] == s[j + 1]) {
                j++;
            }
            next[i] = j;
        }
    }
    int strStr(string haystack, string needle) {
        if(needle.length() == 0) {
            return 0;
        }
        int next[needle.length()];
        // 填充前缀表
        getNext(next, needle);
        // j + 1 表示当前已经匹配成功的长度
        // j = -1 表示当前无匹配成功的字符
        int j = -1;
        for(int i = 0; i < haystack.length(); i++) {
            // 失配
            while(j >= 0 && haystack[i] != needle[j + 1]) {
                j = next[j];
            }
            // 匹配成功，j自增
            if(haystack[i] == needle[j + 1]) {
                j++;
            }
            // 找到一个成功匹配的串，返回其起始位置
            if(j + 1 == needle.length()) {
                return (i - j);
            }
        }
        return -1;
    }
};