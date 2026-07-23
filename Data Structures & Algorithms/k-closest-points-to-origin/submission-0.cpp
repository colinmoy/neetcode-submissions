class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> result;
        priority_queue<pair<int, pair<int, int>>> q;
        for (vector<int> point : points) {
            int dist = point[0] * point[0] + point[1] * point[1];
            q.push({dist, {point[0], point[1]}});
        }
        while (!q.empty()) {
            result.push_back({q.top().second.first, q.top().second.second});
            q.pop();
            if (result.size() > k) {
                result.erase(result.begin());
            }
        }
        return result;
    }
};
