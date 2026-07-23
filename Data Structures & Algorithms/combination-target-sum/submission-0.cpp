class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        queue<vector<int>> vs;
        queue<int> sums;
        vector<vector<int>> result;
        for (int n : nums) {
            if (n <= target) {
                vector<int> temp = {n};
                vs.push(temp);
                sums.push(n);
            }
        }
        while (!vs.empty()) {
            if (sums.front() == target) {
                result.push_back(vs.front());
            } else {
                for (int n : nums) {
                    if (n <= vs.front()[vs.front().size() - 1] && n + sums.front() <= target) {
                        vector<int> temp(vs.front());
                        temp.push_back(n);
                        vs.push(temp);
                        sums.push(sums.front() + n);
                    }
                }
            }
            vs.pop();
            sums.pop();
        }
        return result;
    }
};
