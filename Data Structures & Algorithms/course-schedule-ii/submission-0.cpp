class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> result;
        unordered_map<int, set<int>> pre;
        for (vector<int> prereq : prerequisites) {
            pre[prereq[0]].insert(prereq[1]);
        }
        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (pre[i].size() == 0) {
                q.push(i);
            }
        }
        while (!q.empty()) {
            int x = q.front();
            q.pop();
            for (int i = 0; i < numCourses; i++) {
                if (pre[i].size() == 0) {
                    continue;
                }
                pre[i].erase(x);
                if (pre[i].size() == 0) {
                    q.push(i);
                }
            }
            result.push_back(x);
        }
        if (result.size() != numCourses) {
            result.clear();
        }
        return result;
    }
};
