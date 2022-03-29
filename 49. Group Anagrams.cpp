class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string> > mp;
        vector<vector<string> > ans;
        for(int i = 0; i < strs.size(); i++) {
            string temp = strs[i];
            sort(temp.begin(), temp.end());
            mp[temp].push_back(strs[i]);
        }
        for(unordered_map<string, vector<string> >::iterator i = mp.begin(); i != mp.end(); i++) {
            ans.push_back(i->second);
        }
        return ans;
    }
};