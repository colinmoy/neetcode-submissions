class Solution {
public:
    int rob(vector<int>& nums) {
        int result = nums[0];
        vector<int> dp(nums.size());
        for (unsigned i = 0; i < 2 && i < nums.size(); i++) {
            dp[i] = nums[i];
        }
        for (unsigned i = 1; i < dp.size(); i++) {
            if (i == 2) {
                dp[i] = nums[i] + dp[i-2];
            } else if (i > 2) {
                dp[i] = nums[i] + max(dp[i-2], dp[i-3]);
            }
            if (dp[i] > result) {
                result = dp[i];
            }
        }
        return result;
    }
};
