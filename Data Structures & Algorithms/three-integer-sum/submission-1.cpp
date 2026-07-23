class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        set<vector<int>> set;
        for (unsigned i = 0; i < nums.size(); i++) {
            for (unsigned j = i + 1; j < nums.size(); j++) {
                for (unsigned k = j + 1; k < nums.size(); k++) {
                    if (nums[i] + nums[j] + nums[k] == 0) {
                        vector<int> temp = {nums[i], nums[j], nums[k]};
                        sort(temp.begin(), temp.end());
                        if (set.find(temp) == set.end()) {
                            result.push_back(temp);
                            set.insert(temp);
                        }
                    }
                }
            }
        }
        return result;
    }
};
