class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int l = 0, r = matrix.size() * matrix[0].size() - 1, m;
        while (l <= r) {
            m = (l + r)/2;
            int curr = matrix[m / matrix[0].size()][m % matrix[0].size()];
            if (curr == target) {
                return true;
            } else if (curr < target) {
                l = m + 1;
            } else {
                r = m - 1;
            }
        }
        return false;
    }
};
