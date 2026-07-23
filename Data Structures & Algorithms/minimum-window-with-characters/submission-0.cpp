class Solution {
public:
    string minWindow(string s, string t) {
        map<char, int> req;
        for (char c : t) {
            req[c]++;
        }
        for (unsigned i = 1; i <= s.size(); i++) {
            for (unsigned j = 0; j <= s.size() - i; j++) {
                string pot = s.substr(j, i);
                map<char, int> curr;
                for (char c : pot) {
                    curr[c]++;
                }
                bool next = false;
                for (auto m : req) {
                    if (curr[m.first] < m.second) {
                        next = true;
                        break;
                    }
                }
                if (!next) {
                    return pot;
                }
            }
        }
        return "";
    }
};
