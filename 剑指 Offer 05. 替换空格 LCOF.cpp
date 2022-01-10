class Solution {
public:
    string replaceSpace(string s) {
        // 统计 s 中空格个数
        int count = 0;
        // 记录原字符串长度
        int originalSize = s.size();

        for (int i = 0; i < s.length(); i++) {
            if (s[i] == ' ') {
                count++;
            }
        }
        // 将字符串扩充至所需要的长度
        s.resize(originalSize + count * 2);
        // 记录新字符串长度
        int newSize = s.size();

        int left, right;
        // 双指针分别指向原字符串末尾和新字符串末尾
        // 当 s[left] 不为空格时，复制到新字符串对应位置
        // 当 s[left] 为空格时，将新字符串位置替换为 "%20"
        for (left = originalSize - 1, right = newSize - 1; left < right; left--, right--) {
            if (s[left] != ' ') {
                s[right] = s[left];
            } else {
                s[right] = '0';
                s[right - 1] = '2';
                s[right - 2] = '%';
                right -= 2;
            }
        }
        return s;
    }
};