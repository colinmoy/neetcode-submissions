class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int result = INT_MAX, l = 0, sum = 0;
        for (int r = 0; r < nums.size(); r++) {
            sum += nums[r];
            while (sum >= target) {
                result = min(result, r - l + 1);
                sum -= nums[l];
                l++;
            }
        }
        if (result == INT_MAX) {
            return 0;
        }
        return result;
    }
};