class Solution {
public:
    void reverseString(vector<char>& s) {
        if(s.size() <= 1){
            return;
        }
        int tmp;
        for(int i = 0; i < s.size()/2; i++){
            if(s[i] != s[s.size()-1-i]){
                tmp = s[i];
                s[i] = s[s.size()-1-i];
                s[s.size()-1-i] = tmp;            
            }
        }
    }
};