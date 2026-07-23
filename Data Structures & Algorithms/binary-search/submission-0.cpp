class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1, m = (l + r)/2;
        while (l < r && nums[m] != target) {
            if (nums[m] > target) {
                r = m - 1;
            } else {
                l = m + 1;
            }
            m = (l + r)/2;
        }
        if (nums[m] == target) {
            return m;
        }
        return -1;
    }
};
