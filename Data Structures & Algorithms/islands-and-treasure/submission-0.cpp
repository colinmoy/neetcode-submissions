class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int dirs[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 0) {
                    queue<pair<int, int>> q;
                    q.push({i, j});
                    while (!q.empty()) {
                        pair<int, int> p = q.front();
                        q.pop();
                        for (auto dir : dirs) {
                            pair<int, int> next = {p.first + dir[0], p.second + dir[1]};
                            if (next.first >= 0 && next.first < grid.size() && next.second >= 0 && next.second < grid[0].size() && grid[p.first][p.second] + 1 < grid[next.first][next.second]) {
                                grid[next.first][next.second] = grid[p.first][p.second] + 1;
                                q.push(next);
                            }
                        }
                    }
                }
            }
        }
    }
};
