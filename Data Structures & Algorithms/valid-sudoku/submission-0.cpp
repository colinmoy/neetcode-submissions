class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for (unsigned i = 0; i < 9; i++) {
            set<char> set;
            for (unsigned j = 0; j < 9; j++) {
                if (board[i][j] != '.' && set.find(board[i][j]) != set.end()) {
                    return false;
                } else {
                    set.insert(board[i][j]);
                }
            }
        }
        for (unsigned i = 0; i < 9; i++) {
            set<char> set;
            for (unsigned j = 0; j < 9; j++) {
                if (board[j][i] != '.' && set.find(board[j][i]) != set.end()) {
                    return false;
                } else {
                    set.insert(board[j][i]);
                }
            }
        }
        for (int i = 0; i < 9; i += 3) {
            for (int j = 0; j < 9; j += 3) {
                set<char> set;
                for (int dx = 0; dx < 3; dx++) {
                    for (int dy = 0; dy < 3; dy++) {
                        char c = board[i + dx][j + dy];
                        if (c != '.' && set.find(c) != set.end()) {
                            return false;
                        } else {
                            set.insert(c);
                        }
                     }
                }
            }
        }
        return true;
    }
};
