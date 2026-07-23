class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, set<int>> deg;
        for (vector<int> prereq : prerequisites) {
            deg[prereq[0]].insert(prereq[1]);
        }
        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (deg[i].size() == 0) {
                q.push(i);
            }
        }
        int removes = 0;
        while (!q.empty()) {
            int x = q.front();
            q.pop();
            removes++;
            for (int i = 0; i < numCourses; i++) {
                if (deg[i].size() == 0) {
                    continue;
                }
                deg[i].erase(x);
                if (deg[i].size() == 0) {
                    q.push(i);
                }
            }
        }
        return removes == numCourses;
    }
};
