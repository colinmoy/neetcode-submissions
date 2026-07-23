class Solution {
public:
    int numDecodings(string s) {
        if (s[0] == '0') {
            return 0;
        }
        if (s.size() <= 1) {
            return 1;
        }
        int result = 0;
        if (stoi(s.substr(0, 2)) <= 26) {
            result += numDecodings(s.substr(2));
        }
        result += numDecodings(s.substr(1));
        return result;
    }
};
