class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        for (unsigned i = 0; i < board.size(); i++) {
            for (unsigned j = 0; j < board[0].size(); j++) {
                if (dfs(board, word, i, j, 0)) {
                    return true;
                }
            }
        }
        return false;
    }

private:
    set<pair<int, int>> s;
    bool dfs(vector<vector<char>>& board, string word, int r, int c, int i) {
        if (i == word.size()) {
            return true;
        }
        int rows = board.size(), cols = board[0].size();
        if (r < 0 || c < 0 || r >= rows || c >= cols || board[r][c] != word[i] || s.find({r,c}) != s.end()) {
            return false;
        }
        s.insert({r,c});
        bool result = dfs(board, word, r + 1, c, i + 1) || dfs(board, word, r - 1, c, i + 1) || dfs(board, word, r, c + 1, i + 1) || dfs(board, word, r, c - 1, i + 1);
        s.erase({r,c});
        return result;
    }
};
