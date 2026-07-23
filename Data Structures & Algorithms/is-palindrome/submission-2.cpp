class Solution {
public:
    bool isPalindrome(string s) {
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        set<char> set;
        string alphabet = "abcdefghijklmnopqrstuvwxyz1234567890";
        for (char c : alphabet) {
            set.insert(c);
        }
        int i = 0, j = s.size() - 1;
        while (set.find(s[i]) == set.end()) {
            i++;
        }
        while (set.find(s[j]) == set.end()) {
            j--;
        }
        while (i < j) {
            while (set.find(s[i]) == set.end()) {
                i++;
            }
            while (set.find(s[j]) == set.end()) {
                j--;
            }
            if (s[i] != s[j]) {
                return false;
            } else {
                i++;
                j--;
            }
        }
        return true;
    }
};
