class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> inDegree(numCourses, 0);
        vector<int> ans;
        // mp用于记录该课程的后续课程数组
        map<int, vector<int>> mp;
        for(int i = 0; i < prerequisites.size(); i++) {
            // 记录入度
            inDegree[prerequisites[i][0]]++;
            // 记录后续课程
            mp[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        // BFS所需的队列
        queue<int> que;
        for(int i = 0; i < numCourses; i++) {
            // 入度为 0 代表不需要先修课
            if(inDegree[i] == 0) {
                que.push(i);
                ans.push_back(i);
            }
        }
        while(!que.empty()) {
            // 出队，同时将该课后续课程入度减一，将入度为0的课程继续入队
            int val = que.front();
            que.pop();
            vector<int> afterCource = mp[val];
            if(afterCource.size() > 0) {
                for(int i = 0; i < afterCource.size(); i++) {
                    inDegree[afterCource[i]]--;
                    if(inDegree[afterCource[i]] == 0) {
                        que.push(afterCource[i]);
                        ans.push_back(afterCource[i]);
                    }
                }
            }
        }
        if(ans.size() != numCourses) {
            ans.clear();
        }
        return ans;
    }
};