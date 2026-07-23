class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> result;
        for (int i = 0; i <= n; i++) {
            int x = i, temp = 0;
            while (x > 0) {
                temp += x & 1;
                x >>= 1;
            }
            result.push_back(temp);
        }
        return result;
    }
};
