class Solution {
public:
    vector<vector<string>> partition(string s) {
        result.clear();
        vector<string> curr;
        dfs(s, curr, 0);
        return result;
    }

private:
    vector<vector<string>> result;

    void dfs(string s, vector<string>& curr, int i) {
        if (i == s.size()) {
            result.push_back(curr);
            return;
        }
        char c = s[i];
        for (int j = i; j < s.size(); j++) {
            string ss = s.substr(i, j - i + 1);
            string ss2 = ss;
            reverse(ss2.begin(), ss2.end());
            if (ss == ss2) {
                curr.push_back(ss);
                dfs(s, curr, j + 1);
                curr.pop_back();
            }
        }
    }
};
