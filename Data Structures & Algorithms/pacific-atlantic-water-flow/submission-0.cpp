class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>> result;
        int dirs[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        for (int i = 0; i < heights.size(); i++) {
            for (int j = 0; j < heights[0].size(); j++) {
                queue<pair<int, int>> q;
                set<pair<int, int>> visited;
                q.push({i, j});
                visited.insert({i, j});
                bool pac = i == 0 || j == 0, atl = i == heights.size() - 1 || j == heights[0].size() - 1;
                while (!q.empty()) {
                    if (pac && atl) {
                        break;
                    }
                    pair<int, int> p = q.front();
                    q.pop();
                    if (p.first == 0 || p.second == 0) {
                        pac = true;
                    }
                    if (p.first == heights.size() - 1 || p.second == heights[0].size() - 1) {
                        atl = true;
                    }
                    for (auto dir : dirs) {
                        pair<int, int> next = {p.first + dir[0], p.second + dir[1]};
                        if (next.first >= 0 && next.first < heights.size() && next.second >= 0 && next.second < heights[0].size() && visited.find(next) == visited.end() && heights[next.first][next.second] <= heights[p.first][p.second]) {
                            visited.insert(next);
                            q.push(next);
                        }
                    }
                }
                if (pac && atl) {
                    result.push_back({i, j});
                }
            }
        }
        return result;
    }
};
