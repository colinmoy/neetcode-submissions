class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.size() == 0) {
            return vector<string>();
        }
        unordered_map<char, vector<char>> map;
        map['2'] = {'a', 'b', 'c'};
        map['3'] = {'d', 'e', 'f'};
        map['4'] = {'g', 'h', 'i'};
        map['5'] = {'j', 'k', 'l'};
        map['6'] = {'m', 'n', 'o'};
        map['7'] = {'p', 'q', 'r', 's'};
        map['8'] = {'t', 'u', 'v'};
        map['9'] = {'w', 'x', 'y', 'z'};
        dfs(digits, map, "", 0);
        return result;
    }

private:
    vector<string> result;

    void dfs(string digits, unordered_map<char, vector<char>> map, string curr, int i) {
        if (i == digits.size()) {
            result.push_back(curr);
            return;
        }
        for (char c : map[digits[i]]) {
            curr += c;
            dfs(digits, map, curr, i + 1);
            curr = curr.substr(0, curr.size() - 1);
        }
    }
};
