class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> result;
        map<int, int> map;
        for (int num : nums) {
            map[num]++;
        }
        vector<int> counts;
        for (auto m : map) {
            counts.push_back(m.second);
            push_heap(counts.begin(), counts.end());
        }
        for (int i = 1; i < k; i++) {
            pop_heap(counts.begin(), counts.end());
            counts.pop_back();
        }
        int min = counts[0];
        for (auto m : map) {
            if (m.second >= min) {
                result.push_back(m.first);
            }
        }
        return result;
    }
};
