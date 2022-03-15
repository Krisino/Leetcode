class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        unordered_map<string, int> mp;
        vector<string> result;
        int minIndex = INT_MAX;
        for(int i = 0; i < list1.size(); i++) {
            mp.insert(pair<string, int>(list1[i], i));
        }
        for(int i = 0; i < list2.size(); i++) {
            if(mp.find(list2[i]) != mp.end()) {
                if(mp[list2[i]] + i < minIndex) {
                    minIndex = mp[list2[i]] + i;
                    result.clear();
                    result.push_back(list2[i]);
                } else if(mp[list2[i]] + i == minIndex) {
                    result.push_back(list2[i]);
                }
            }
        }
        return result;
    }
};