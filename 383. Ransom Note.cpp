class Solution {
public:
    // 方法一
    // 暴力法，循环遍历
    bool canConstruct(string ransomNote, string magazine) {
        for(int i = 0; i < magazine.size(); i++) {
            for(int j = 0; j < ransomNote.size(); j++) {
                // 如果 magazine 中有 ransomNote 的字符，则删除该字符
                if(magazine[i] == ransomNote[j]) {
                    ransomNote.erase(ransomNote.begin() + j);
                    break;
                }
            }
        }
        // 如果 ransomNote 的长度为 0 说明 magazine 里有 ransomNote 的所有字符
        if (ransomNote.length() == 0) {
            return true;
        }
        return false;
        
    }
    
    // 方法二
    // 使用数组计数
    bool canConstruct(string ransomNote, string magazine) {
        int record[26] = {0};
        // 记录 magazine 内字符数量
        for (int i = 0; i < magazine.length(); i++) {
            record[magazine[i]-'a'] ++;
        }
        // 减去 ransomNote 中字符数量
        for (int j = 0; j < ransomNote.length(); j++) {
            record[ransomNote[j]-'a']--;
            // 小于零说明 magazine 内特定字符数量不够
            if(record[ransomNote[j]-'a'] < 0) {
                return false;
            }
        }
        return true;
    }
};