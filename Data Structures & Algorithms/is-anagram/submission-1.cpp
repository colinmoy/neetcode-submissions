#include <map>

class Solution {
public:
    bool isAnagram(string s, string t) {
        map<char, int> m1;
        map<char, int> m2;
        for (char c : s) {
            m1[c]++;
        }
        for (char c : t) {
            m2[c]++;
        }
        for (auto m : m1) {
            if (m2[m.first] != m.second) {
                return false;
            }
        }
        for (auto m : m2) {
            if (m1[m.first] != m.second) {
                return false;
            }
        }
        return true;
    }
};
