class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int result = 0;
        for (unsigned i = 0; i < s.size(); i++) {
            set<char> set;
            int temp = 0;
            unsigned j = i;
            while (j < s.size() && set.find(s[j]) == set.end()) {
                set.insert(s[j]);
                temp++;
                j++;
            }
            if (temp > result) {
                result = temp;
            }
            set.clear();
        }
        return result;
    }
};
