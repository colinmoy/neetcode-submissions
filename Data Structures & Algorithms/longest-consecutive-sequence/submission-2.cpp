class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        }
        int min = nums[0], max = nums[0];
        set<int> set;
        for (int num : nums) {
            if (num < min) {
                min = num;
            } else if (num > max) {
                max = num;
            }
            set.insert(num);
        }
        int result = 0;
        for (int i = min; i <= max; i++) {
            int temp = 0;
            while (set.find(i) != set.end()) {
                temp++;
                i++;
            }
            if (temp > result) {
                result = temp;
            }
        }
        return result;
    }
};
