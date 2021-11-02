class Solution {
public:
    int myAtoi(string s) {
        vector<int> arr;
        int pos = 0;
        bool isPositive = true;
        bool isEnsured = false;
        int max[] = {2,1,4,7,4,8,3,6,4,7};
        int min[] = {2,1,4,7,4,8,3,6,4,8};
        while(s[pos] == ' ') {
            pos++;
        }
        while(pos < s.length()) {
            if(s[pos] >= '0' && s[pos] <= '9') {
                    arr.push_back(s[pos] - '0');
            } else if(s[pos] == '-') {
                if(isEnsured){
                    break;
                }
                if(arr.size() != 0) {
                    break;
                }
                isPositive = false;
                isEnsured = true;
            } else if(s[pos] == '+'){
                if(isEnsured) {
                    break;
                }
                if(arr.size() != 0) {
                    break;
                }
                isEnsured = true;
            } else {
                if(arr.size() == 0) {
                    return 0;
                }
                break;
            }
            pos++;
        }
        int tmp = 0;
        while(arr.size() && arr[tmp] == 0) {
            arr.erase(arr.begin());
        }
        int n = arr.size();
        if(n > 10) {
            return isPositive?2147483647:-1*2147483648;
        } else if(n == 10) {
            for(int j = 0; j < n; j++) {
                if(arr[j] > (isPositive?max[j]:min[j])) {
                    return isPositive?2147483647:-1*2147483648;
                } else if(arr[j] < (isPositive?max[j]:min[j])) {
                    break;
                }
            }
        }
        int ans = 0;
        for(int j = 0; j < n; j++){
            if(isPositive)
                ans = ans*10 + arr[j];
            else
                ans = ans*10 - arr[j];
        }

        return ans;
    }
};