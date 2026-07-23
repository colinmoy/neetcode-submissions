class Solution {
public:
    bool isHappy(int n) {
        set<int> ns;
        ns.insert(n);
        while (n != 1) {
            int x = n;
            n = 0;
            while (x > 0) {
                n += (x % 10) * (x % 10);
                x /= 10;
            }
            if (ns.find(n) == ns.end()) {
                ns.insert(n);
            } else {
                return false;
            }
        }
        return true;
    }
};
