class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int result = 0;
        int dirs[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                int curr = 0;
                if (grid[i][j] == 1) {
                    queue<pair<int, int>> q;
                    q.push({i, j});
                    while (!q.empty()) {
                        pair<int, int> p = q.front();
                        q.pop();
                        if (grid[p.first][p.second] == 1) {
                            grid[p.first][p.second] = 0;
                            curr++;
                        } else {
                            continue;
                        }
                        for (auto dir : dirs) {
                            pair<int, int> next = {p.first + dir[0], p.second + dir[1]};
                            if (next.first >= 0 && next.first < grid.size() && next.second >= 0 && next.second < grid[0].size() && grid[next.first][next.second] == 1) {
                                q.push(next);
                            }
                        }
                    }
                }
                result = max(result, curr);
            }
        }
        return result;
    }
};
