class Solution {
public:
    int countSubstrings(string s) {
        int result = 0;
        for (int i = 0; i < s.size(); i++) {
            result++;
            int l = i, r = i;
            while (l > 0 && r + 1 < s.size() && s[l - 1] == s[r + 1]) {
                result++;
                l--;
                r++;
            }
            if (i + 1 >= s.size() || s[i] != s[i + 1]) {
                continue;
            }
            l = i;
            r = i + 1;
            result++;
            while (l > 0 && r + 1 < s.size() && s[l - 1] == s[r + 1]) {
                result++;
                l--;
                r++;
            }
        }
        return result;
    }
};
