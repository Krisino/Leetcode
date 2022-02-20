class Solution {
public:
    string multiply(string num1, string num2) {
        vector<int> numberOne, numberTwo;
        int len1 = num1.length();
        int len2 = num2.length();
        for(int i = len1 - 1; i >= 0; i--) {
            numberOne.push_back(num1[i] - '0');
        }
        for(int j = len2 - 1; j >= 0; j--) {
            numberTwo.push_back(num2[j] - '0');
        }
        vector<int> result(len1 + len2);
        for(int i = 0; i < len1; i++) {
            for(int j = 0; j < len2; j++) {
                result[i + j] += numberOne[i] * numberTwo[j];
            }
        }
        int temp = 0;
        for(int i = 0; i < len1 + len2; i++) {
            result[i] += temp;
            temp = result[i] / 10;
            result[i] %= 10;
        }
        int pos = len1 + len2 - 1;
        while(pos > 0 && result[pos] == 0) {
            pos--;
        }
        string ans;
        while(pos >= 0) {
            ans += result[pos] + '0';
            pos--;
        }
        return ans;
    }
};