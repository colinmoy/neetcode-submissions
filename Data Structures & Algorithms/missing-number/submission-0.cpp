class Solution {
public:
    int missingNumber(vector<int>& nums) {
        /*
        01
        10
        11
        00

        00
        10
        01
        */

        int result = nums.size();
        for (int i = 0; i < nums.size(); i++) {
            result ^= i ^ nums[i];
        }
        return result;
    }
};
