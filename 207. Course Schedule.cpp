class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> inDegree(numCourses, 0);
        map<int, vector<int>> mp;
        for(int i = 0; i < prerequisites.size(); i++) {
            inDegree[prerequisites[i][0]]++;
            mp[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        queue<int> que;
        for(int i = 0; i < numCourses; i++) {
            if(inDegree[i] == 0) {
                que.push(i);
            }
        }
        int courseCount = 0;
        while(!que.empty()) {
            courseCount++;
            int val = que.front();
            que.pop();
            vector<int> afterCource = mp[val];
            if(afterCource.size() > 0) {
                for(int i = 0; i < afterCource.size(); i++) {
                    inDegree[afterCource[i]]--;
                    if(inDegree[afterCource[i]] == 0) {
                        que.push(afterCource[i]);
                    }
                }
            }
        }
        return courseCount == numCourses;
    }
};