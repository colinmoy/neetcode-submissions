class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> ct;
        for (int num : nums) {
            ct[num]++;
        }
        vector<vector<int>> buckets(nums.size());
        for (auto m : ct) {
            buckets[m.second - 1].push_back(m.first);
        }
        vector<int> result;
        for (int i = nums.size() - 1; i >= 0; i--) {
            for (int x : buckets[i]) {
                result.push_back(x);
            }
            if (result.size() >= k) {
                return result;
            }
        }
        return result;
    }
};
