#include <map>

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> m;
        for (unsigned i = 0; i < nums.size(); i++) {
            if (m.find(target - nums[i]) != m.end()) {
                return vector<int>({m[target - nums[i]], i});
            } else {
                m[nums[i]] = i;
            }
        }
    }
};
