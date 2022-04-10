class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        string dic[] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        unordered_set<string> st;
        for(int i = 0; i <words.size(); i++) {
            string s = "";
            for(int j = 0; j < words[i].size(); j++) {
                s += dic[words[i][j] - 'a'];
            }
            if(st.find(s) == st.end()) {
                st.insert(s);
            }
        }
        return st.size();
    }
};