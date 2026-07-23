class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char, int> m1;
        for (char c : s1) {
            m1[c]++;
        }
        unordered_map<char, int> m2;
        int l = 0, r = 0;
        while (l <= r && l < (int) s2.size()) {
            m2[s2[r]]++;
            while (m2[s2[r]] > m1[s2[r]]) {
                m2[s2[l]]--;
                l++;
            }
            r++;
            if (r - l == (int) s1.size()) {
                return true;
            }
        }
        return false;
    }
};
