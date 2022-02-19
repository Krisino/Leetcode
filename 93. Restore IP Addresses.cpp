class Solution {
public:
    vector<string> result;

    bool isValid(const string& str, int start, int end) {
        if(start > end) {
            return false;
        } else if(str[start] == '0' && start != end) {
            return false;
        } else if((end - start + 1) > 3) {
            return false;
        }
        int num = 0;
        for(int i = start; i <= end; i++) {
            if(str[i] < '0' || str[i] > '9') {
                return false;
            } else {
                num = num * 10 + str[i] - '0';
            }
            if(num > 255) {
                return false;
            }
        }
        return true;
    }

    void backtrack(string& str, int startIndex, int partitionNum) {
        if(partitionNum == 3) {
            if(isValid(str, startIndex, str.size() - 1)) {
                result.push_back(str);
            }
            return;
        }
        for(int i = startIndex; i < str.size(); i++) {
            if(isValid(str, startIndex, i)) {
                str.insert(str.begin() + i + 1, '.');
                partitionNum++;
                backtrack(str, i + 2, partitionNum);
                partitionNum--;
                str.erase(str.begin() + i + 1);
            } else {
                break;
            }
        }
    }

    vector<string> restoreIpAddresses(string s) {
        result.clear();
        if(s.size() > 12) {
            return result;
        }
        backtrack(s, 0, 0);
        return result;
    }
};