class Solution {
public:
    string one = "qwertyuiopQWERTYUIOP";
    string two = "asdfghjklASDFGHJKL";
    string three = "zxcvbnmZXCVBNM";

    unordered_map<char, int> m1,m2,m3;
    vector<string> findWords(vector<string>& words) {
        for (auto c: one) {
            m1[c]++;
        }
        for (auto c: two) {
            m2[c]++;
        }
        for (auto c: three) {
            m3[c]++;
        }

        vector<string> ans;
        for (auto word: words) {
            bool b1 = true;
            bool b2 = true;
            bool b3 = true;

            for (auto c: word) {
                b1 &= m1[c];
                b2 &= m2[c];
                b3 &= m3[c];
            }
            
            if (b1 || b2 || b3) ans.push_back(word);
        }

        return ans;
    }
};