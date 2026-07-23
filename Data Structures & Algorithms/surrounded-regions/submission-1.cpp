class Solution {
public:
    void solve(vector<vector<char>>& board) {
        set<pair<int, int>> visited;
        int dirs[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (visited.find({i, j}) == visited.end() && board[i][j] == 'O') {
                    visited.insert({i, j});
                    queue<pair<int, int>> q;
                    q.push({i, j});
                    vector<pair<int, int>> group;
                    group.push_back({i, j});
                    bool surrounded = i != 0 && i != board.size() - 1 && j != 0 && j != board[0].size() - 1;
                    while (!q.empty()) {
                        pair<int, int> p = q.front();
                        q.pop();
                        if (p.first == 0 || p.first == board.size() - 1 || p.second == 0 || p.second == board[0].size() - 1) {
                            surrounded = false;
                        }
                        for (auto dir : dirs) {
                            pair<int, int> next = {p.first + dir[0], p.second + dir[1]};
                            if (next.first >= 0 && next.first < board.size() && next.second >= 0 && next.second < board[0].size() && visited.find(next) == visited.end() && board[next.first][next.second] == 'O') {
                                q.push(next);
                                group.push_back(next);
                                visited.insert(next);
                            }
                        }
                    }
                    if (surrounded) {
                        for (pair<int, int> cell : group) {
                            board[cell.first][cell.second] = 'X';
                        }
                    }
                }
            }
        }
    }
};
