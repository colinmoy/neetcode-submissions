class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        sort(stones.begin(), stones.end(), greater<int>());
        while (stones.size() > 1) {
            if (stones[0] == stones[1]) {
                stones.erase(stones.begin());
                stones.erase(stones.begin());
            } else {
                int ind = stones[0] > stones[1] ? 0 : 1;
                stones[ind] -= stones[1 - ind];
                stones.erase(stones.begin() + 1 - ind);
                sort(stones.begin(), stones.end(), greater<int>());
            }
        }
        if (stones.size() == 0) {
            return 0;
        }
        return stones[0];
    }
};
