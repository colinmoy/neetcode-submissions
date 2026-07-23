class Solution {
public:
    string longestPalindrome(string s) {
        string result = "";
        for (int i = 0; i < s.size(); i++) {
            int l = i, r = i;
            while (l > 0 && r + 1 < s.size() && s[l - 1] == s[r + 1]) {
                l--;
                r++;
            }
            if (r - l + 1 > result.size()) {
                result = s.substr(l, r - l + 1);
            }
            if (i + 1 >= s.size() || s[i] != s[i + 1]) {
                continue;
            }
            l = i;
            r = i + 1;
            while (l > 0 && r + 1 < s.size() && s[l - 1] == s[r + 1]) {
                l--;
                r++;
            }
            if (r - l + 1 > result.size()) {
                result = s.substr(l, r - l + 1);
            }
        }
        return result;
    }
};
