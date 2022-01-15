class Solution {
public:
    class myComparison {
    public:
        bool operator()(const pair<int, int>&lhs, const pair<int, int>& rhs) {
            return lhs.second > rhs.second;
        }
    };
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int>map;
        for(int num: nums) {
            map[num]++;
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, myComparison>pri_que;
        for(unordered_map<int, int>::iterator it = map.begin();it != map.end(); it++) {
            pri_que.push(*it);
            if(pri_que.size() > k) {
                pri_que.pop();
            }
        }
        vector<int> result(k);
        for(int i = 0; i < k; i++) {
            result[i] = pri_que.top().first;
            pri_que.pop();
        }
        return result;
    }
};