class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size()){
            return false;
        }
        int map[26] = {0};
        for(int i = 0;i < s.size(); i ++ ){
            map[s[i] - 'a']++;
            map[t[i] - 'a']--;
        }
        for(int i = 0; i < 26; i ++ ){
            if(map[i]){
                return false;
            }
        }
        return true;
    }
};
