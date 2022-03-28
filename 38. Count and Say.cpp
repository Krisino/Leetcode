class Solution {
public:
    // circulation:
    // string countAndSay(int n) {
    //     string pre = "1";
    //     for(int i = 2; i <= n; i++) {
    //         string cur = "";
    //         for(int j = 0; j < pre.size();) {
    //             int k = j + 1;
    //             while(k < pre.size() && pre[j] == pre[k]) {
    //                 k++;
    //             }
    //             cur += to_string(k - j) + pre[j];
    //             j = k;
    //         }
    //         pre = cur;
    //     }
    //     return pre;
    // }

    // recursion:
    string traverse(int n) {
        if(n == 1) {
            return "1";
        }
        string pre = traverse(n - 1);
        string cur = "";
        for(int i = 0; i < pre.size();) {
            int k = i + 1;
            while(pre[i] == pre[k] && k < pre.size()) {
                k++;
            }
            cur += to_string(k - i) + pre[i];
            i = k;
        }
        return cur;
    }

    string countAndSay(int n) {
        return traverse(n);
    }
};