class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        queue<vector<int>> q;
        q.push({nums[0]});
        while (!q.empty()) {
            if (q.front().size() == nums.size()) {
                result.push_back(q.front());
            } else {
                for (unsigned i = 0; i <= q.front().size(); i++) {
                    vector<int> temp(q.front());
                    temp.insert(temp.begin() + i, nums[q.front().size()]);
                    q.push(temp);
                }
            }
            q.pop();
        }
        return result;
    }
};
