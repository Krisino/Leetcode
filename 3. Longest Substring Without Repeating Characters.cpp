class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.length() <= 1) return s.length();
        int ans = 0,start = 0;
        unordered_set<char> lookup;
        for(int i = 0; i < s.length(); i++){
            while(lookup.find(s[i]) != lookup.end()){
                lookup.erase(s[start]);
                start++;
            }
            ans = max(ans,i - start + 1);
            lookup.insert(s[i]);
        }
        return ans;
    }
};
