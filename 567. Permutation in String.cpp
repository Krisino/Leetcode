class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size()>s2.size()) return false;
        int len1 = s1.size();
        int len2 = s2.size();
        vector<int> need(26,0);
        vector<int> window(26,0);
        for(int i = 0; i < s1.length(); i++){
            need[s1[i] - 'a']++;
            window[s2[i] - 'a']++;
        }
        for(int i = len1; i < len2; i++){
            if(need == window){
                return true;
            }
            window[s2[i] - 'a']++;
            window[s2[i-len1] - 'a']--;
        }
        return need == window;
    }
};