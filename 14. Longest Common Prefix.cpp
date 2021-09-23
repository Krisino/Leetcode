class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans = "";
        if(strs.size() == 0)    return ans;
        for(int i = 0; i < strs[0].length(); i++ ){
            for(int j = 1; j < strs.size(); j++ ){
                if(i > strs[j].length()-1 || strs[0][i] != strs[j][i]){
                    return ans;
                }
            }
            ans.append(1,strs[0][i]);
        }
        return ans;
    }
};