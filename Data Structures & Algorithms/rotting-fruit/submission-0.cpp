class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int result = 0;
        queue<pair<int, pair<int, int>>> q; // {time, {x, y}}
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 2) {
                    q.push({0, {i, j}});
                }
            }
        }
        int dirs[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        while (!q.empty()) {
            pair<int, pair<int, int>> p = q.front();
            q.pop();
            grid[p.second.first][p.second.second] = 2;
            for (auto dir : dirs) {
                pair<int, int> next = {p.second.first + dir[0], p.second.second + dir[1]};
                if (next.first >= 0 && next.first < grid.size() && next.second >= 0 && next.second < grid[0].size() && grid[next.first][next.second] == 1) {
                    q.push({p.first + 1, next});
                    result = max(p.first + 1, result);
                }
            }
        }
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 1) {
                    return -1;
                }
            }
        }
        return result;
    }
};
