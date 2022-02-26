class Solution {
public:
    string addBinary(string a, string b) {
        if(a == "" || a.length() == 0) {
            return b;
        }
        if(b == "" || b.length() == 0) {
            return a;
        }
        string result = "";
        int i = a.length() - 1;
        int j = b.length() - 1;
        int temp = 0;
        while(i >= 0 || j >= 0) {
            if(i >= 0) {
                temp += a[i] - '0';
                i--;
            }
            if(j >= 0) {
                temp += b[j] - '0';
                j--;
            }
            result.push_back(temp % 2 + '0');
            temp = temp / 2;
        }
        if(temp != 0) {
            result.push_back(temp + '0');
        }
        reverse(result.begin(), result.end());
        return result;
    }
};