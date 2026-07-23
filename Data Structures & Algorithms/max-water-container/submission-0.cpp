class Solution {
public:
    int maxArea(vector<int>& heights) {
        int result = 0;
        for (unsigned i = 0; i < heights.size(); i++) {
            for (unsigned j = i + 1; j < heights.size(); j++) {
                int min = heights[i];
                if (heights[j] < min) {
                    min = heights[j];
                }
                int temp = min * (j - i);
                if (temp > result) {
                    result = temp;
                }
            }
        }
        return result;
    }
};
