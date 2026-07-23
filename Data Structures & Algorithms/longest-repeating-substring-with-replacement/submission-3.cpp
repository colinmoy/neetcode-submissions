class Solution {
public:
    int characterReplacement(string s, int k) {
        int result = 0;
        for (unsigned i = 0; i < s.size(); i++) {
            for (unsigned di = 0; di <= k; di++) {
                int temp = 0, ktemp = k;
                char c = s[i + di];
                unsigned j = i;
                while (j < s.size() && (s[j] == c || ktemp > 0)) {
                    if (s[j] != c) {
                        ktemp--;
                    }
                    temp++;
                    j++;
                }
                if (temp > result) {
                    result = temp;
                }
            }
        }
        return result;
    }
};
