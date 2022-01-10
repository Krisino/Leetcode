class Solution {
public:
    void reverseString(vector<char>& s) {
        // 单个字符无需反转
        if(s.size() <= 1){
            return;
        }
        int tmp;
        for(int i = 0; i < s.size()/2; i++){
            // 如果不相等才交换
            if(s[i] != s[s.size()-1-i]){
                tmp = s[i];
                s[i] = s[s.size()-1-i];
                s[s.size()-1-i] = tmp;            
            }
        }
    }
};