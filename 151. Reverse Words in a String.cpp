class Solution {
public:
    // 将字符串 s 的 [start, end] 部分反转
    void reverseString(string & s, int start, int end) {
        for(int i = start, j = end; i < j; i++, j--) {
            swap(s[i], s[j]);
        }
    }

    // 删除字符串 s 中多余的空格
    void removeSpace(string &s) {
        int slow = 0;
        int fast = 0;
        // 去掉字符串首的空格
        while(s.size() > 0 && fast < s.size() && s[fast] == ' ') {
            fast++;
        }
        // 去掉字符串单词中间的冗余空格
        for(; fast < s.size(); fast++) {
            if(fast - 1 > 0 && s[fast] == s[fast - 1] && s[fast] == ' ') {
                continue;
            }else {
                s[slow] = s[fast];
                slow++;
            }
        }
        // 重新设置字符串 s 的长度，删除字符串尾的空格
        if(slow - 1 > 0 && s[slow - 1] == ' ') {
            s.resize(slow - 1);
        }else {
            s.resize(slow);
        }
    }

    /*
        1. 去掉空格
        2. 反转整个字符串
        3. 反转每个字符串中的单词
    */
    string reverseWords(string s) {
        removeSpace(s);
        reverseString(s, 0, s.length() - 1);
        int start = 0;
        int end = 0;
        bool isEntered = false;
        for(int i = 0; i < s.length(); i++) {
            // 设置进入区间开始位置
            if(!isEntered) {
                start = i;
                isEntered = true;
            }
            // 设置进入区间结尾位置
            if(isEntered && s[i] == ' ' && s[i - 1] != ' ') {
                end = i - 1;
                isEntered = false;
                // 反转单个单词
                reverseString(s, start, end);
            }
            // 考虑字符串末尾情况：末尾没有空格进行判断
            if(isEntered && (i == s.length() - 1) && s[i] != ' ') {
                end = i;
                isEntered = false;
                reverseString(s, start, end);
            }
        }
        return s;
    }
};