class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        set<pair<int, int>> visited;
        vector<pair<int, int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        int result = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == '1' && visited.find({i, j}) == visited.end()) {
                    result++;
                    queue<pair<int, int>> q;
                    q.push({i,j});
                    while (!q.empty()) {
                        pair<int, int> p = q.front();
                        q.pop();
                        if (visited.find(p) != visited.end()) {
                            continue;
                        }
                        visited.insert(p);
                        for (pair<int, int> dir : dirs) {
                            pair<int, int> next = {p.first + dir.first, p.second + dir.second};
                            if (next.first >= 0 && next.first < grid.size() && next.second >= 0 && next.second < grid[0].size() && grid[next.first][next.second] == '1') {
                                q.push({next.first, next.second});
                            }
                        }
                    }
                }
            }
        }
        return result;
    }
};
