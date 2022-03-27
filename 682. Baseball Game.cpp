class Solution {
public:
    int calPoints(vector<string>& ops) {
        vector<int> arr;
        for(int i = 0; i < ops.size(); i++) {
            if(ops[i] == "+") {
                arr.push_back(arr[arr.size() - 1] + arr[arr.size() - 2]);
            } else if(ops[i] == "D") {
                arr.push_back(arr[arr.size() - 1] * 2);
            } else if(ops[i] == "C") {
                arr.pop_back();
            } else {
                arr.push_back(stoi(ops[i]));
            }
        }
        return accumulate(arr.begin(), arr.end(), 0);
    }
};