class Solution {
public:
    vector<int> pancakeSort(vector<int>& arr) {
        vector<int> result;
        for(int i = arr.size(); i > 1; i--) {
            int index = max_element(arr.begin(), arr.begin() + i) - arr.begin();
            if(index == i - 1) {
                continue;
            }
            reverse(arr.begin(), arr.begin() + index + 1);
            reverse(arr.begin(), arr.begin() + i);
            result.push_back(index + 1);
            result.push_back(i);
        }
        return result;
    }
};