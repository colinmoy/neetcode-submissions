class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> result(temperatures.size(), 0);
        stack<int> inds;
        inds.push(0);
        for (int ind = 1; ind < temperatures.size(); ind++) {
            while (!inds.empty()) {
                if (temperatures[inds.top()] < temperatures[ind]) {
                    result[inds.top()] = ind - inds.top();
                    inds.pop();
                } else {
                    break;
                }
            }
            inds.push(ind);
        }
        return result;
    }
};
