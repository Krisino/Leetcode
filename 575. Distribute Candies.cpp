class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        int ans = 0;
        int len = candyType.size();
        unordered_set<int> s;
        for(auto i: candyType){
            if(ans >= len/2){
                return ans;
            }
            if(s.find(i) == s.end()){
                ans++;
                s.insert(i);
            }
        }
        return ans;
    }
};