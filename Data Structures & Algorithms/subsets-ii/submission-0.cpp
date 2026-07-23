class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        result.clear();
        sort(nums.begin(), nums.end());
        vector<int> curr;
        dfs(nums, curr, 0);
        return result;
    }

private:
    vector<vector<int>> result;
    
    void dfs(vector<int>& nums, vector<int>& curr, int i) {
        if (i >= nums.size()) {
            result.push_back(curr);
            return;
        }
        curr.push_back(nums[i]);
        dfs(nums, curr, i + 1);
        curr.pop_back();
        while (i + 1 < nums.size() && nums[i] == nums[i+1]) {
            i++;
        }
        dfs(nums, curr, i + 1);
    }
};
