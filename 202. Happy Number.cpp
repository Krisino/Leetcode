class Solution {
public:
    // 计算所有位置上的平方和
    int getSum(int n) {
        int sum = 0;
        while(n) {
            sum += (n % 10) * (n % 10);
            n /= 10;
        }    
        return sum;
    }

    bool isHappy(int n) {
        int sum = n;
        unordered_set<int>mp;
        while(1) {
            sum = getSum(sum);
            // 三种情况：
            // 确定为快乐数、出现无限循环、不确定是否为快乐数
            if(sum == 1) {
                return true;
            } else if (mp.find(sum) != mp.end()) {
                return false;
            } else {
                mp.insert(sum);
            }
        }
    }
};