class Solution {
public:
    string s;
    int n, k;

    int getCount(char c) {
        int count = 0;
        for(int left = 0, right = 0, cnt = 0; right < n; right++) {
            if(s[right] == c) {
                cnt++;
            }
            while(cnt > k) {
                if(s[left] == c) {
                    cnt--;
                }
                left++;
            }
            count = max(count, right - left + 1);
        }
        return count;
    }

    int maxConsecutiveAnswers(string answerKey, int k) {
        s = answerKey;
        n = answerKey.size();
        this->k = k;
        return max(getCount('T'), getCount('F'));
    }
};