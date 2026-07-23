class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        k = nums.size() - k;
        return quickSelect(nums, 0, nums.size() - 1, k);
    }

private:
    int quickSelect(vector<int>& nums, int l, int r, int k) {
        int p = l;
        for (int i = l; i < r; i++) {
            if (nums[i] <= nums[r]) {
                swap(nums[i], nums[p]);
                p++;
            }
        }
        swap(nums[p], nums[r]);
        if (p == k) {
            return nums[p];
        } else if (p > k) {
            return quickSelect(nums, l, p - 1, k);
        } else {
            return quickSelect(nums, p + 1, r, k);
        }
    }
};
