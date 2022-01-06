class Solution {
public:
    bool isAnagram(string s, string t) {
        int lenS = s.length();
        int lenT = t.length();
        if(lenS != lenT) {
            return false;
        }
        // 使用额外数组来记录每个字母出现的次数
        int tempArray[26] = {0};
        // 对于 s 进行字符出现的次数
        for(int i = 0; i < lenS; i++) {
            tempArray[s[i] - 'a']++;
        }
        // 使用已统计的数据来对 t 进行相减
        for(int i = 0; i < lenT; i++) {
            tempArray[t[i] - 'a']--;
        }
        // 若最后统计数组里全为 0, 则说明两个 string 为字母异位词
        for(int i = 0; i < 26; i++) {
            if(tempArray[i] != 0) {
                return false;
            }
        }
        return true;
    }
};