class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        set<vector<int>> set;
        queue<vector<int>> q;
        q.push(nums);
        vector<vector<int>> result;
        while (!q.empty()) {
            if (set.find(q.front()) == set.end()) {
                set.insert(q.front());
                result.push_back(q.front());
                for (unsigned i = 0; i < q.front().size(); i++) {
                    vector<int> temp(q.front());
                    temp.erase(temp.begin() + i);
                    q.push(temp);
                }
            }
            q.pop();
        }
        return result;
    }
};
