class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1, m;
        int r = piles[0];
        for (int pile : piles) {
            r = max(r, pile);
        }
        int result = r;
        while (l <= r) {
            m = (l + r)/2;
            int curr = 0;
            for (int pile : piles) {
                curr += (pile + m - 1) / m;
            }
            if (curr <= h) {
                result = min(m, result);
                r = m - 1;
            } else {
                l = m + 1;
            }
        }
        return result;
    }
};
