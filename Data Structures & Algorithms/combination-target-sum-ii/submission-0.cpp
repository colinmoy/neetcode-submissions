class Solution {
public:
    vector<vector<int>> result;
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        result.clear();
        vector<int> curr;
        dfs(candidates, curr, 0, 0, target);
        return result;
    }

private:
    void dfs(vector<int>& candidates, vector<int>& curr, int i, int sum, int target) {
        if (sum == target) {
            result.push_back(curr);
            return;
        }
        if (sum > target || i >= candidates.size()) {
            return;
        }
        curr.push_back(candidates[i]);
        dfs(candidates, curr, i + 1, sum + candidates[i], target);
        curr.pop_back();
        while (i + 1 < candidates.size() && candidates[i] == candidates[i+1]) {
            i++;
        }
        dfs(candidates, curr, i + 1, sum, target);
    }
};
