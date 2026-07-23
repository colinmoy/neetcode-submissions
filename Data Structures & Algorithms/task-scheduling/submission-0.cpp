class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> map;
        for (char c : tasks) {
            map[c]++;
        }
        priority_queue<int> pq;
        for (auto m : map) {
            pq.push(m.second);
        }
        queue<pair<int, int>> q;
        int time = 0;
        while (!pq.empty() || !q.empty()) {
            time++;
            if (!pq.empty()) {
                int c = pq.top() - 1;
                pq.pop();
                if (c != 0) {
                    q.push({c, time + n});
                }
            }
            if (!q.empty() && q.front().second <= time) {
                pq.push(q.front().first);
                q.pop();
            }
        }
        return time;
    }
};
