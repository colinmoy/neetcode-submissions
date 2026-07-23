class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> result(nums.size(), 1);
        for (unsigned i = 0; i < nums.size(); i++) {
            for (unsigned j = 0; j < nums.size(); j++) {
                if (i != j) {
                    result[i] *= nums[j];
                }
            }
        }
        return result;
    }
};
