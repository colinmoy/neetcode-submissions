class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        digits[digits.size() - 1]++;
        int carry = 0;
        for (int i = (int) digits.size() - 1; i >= 0; i--) {
            digits[i] += carry;
            carry = 0;
            if (digits[i] >= 10) {
                carry += digits[i]/10;
                digits[i] = digits[i] % 10;
            } else {
                break;
            }
        }
        if (carry > 0) {
            digits.insert(digits.begin(), carry);
        }
        return digits;
    }
};
