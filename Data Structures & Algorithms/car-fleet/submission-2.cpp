class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>> ps;
        for (unsigned i = 0; i < position.size(); i++) {
            ps.push_back({position[i], speed[i]});
        }
        sort(ps.rbegin(), ps.rend());
        vector<double> times;
        for (pair<int, int> p : ps) {
            double temp = ((double) target - p.first) / p.second;
            times.push_back(temp);
            if (times.size() > 1 && times[times.size() - 2] >= temp) {
                times.pop_back();
            }
        }
        return times.size();
    }
};
