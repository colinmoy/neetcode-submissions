class TimeMap {
public:
    TimeMap() {
        map.clear();
    }
    
    void set(string key, string value, int timestamp) {
        map[key].push_back({value, timestamp});
    }
    
    string get(string key, int timestamp) {
        vector<pair<string,int>> ps = map[key];
        int l = 0, r = ps.size() - 1;
        string result = "";
        while (l <= r) {
            int m = (l + r)/2;
            int time = ps[m].second;
            if (time <= timestamp) {
                result = ps[m].first;
                l = m + 1;
            } else {
                r = m - 1;
            }
        }
        return result;
    }

private:
    unordered_map<string, vector<pair<string, int>>> map;
};
