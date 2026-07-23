class LRUCache {
public:
    LRUCache(int capacity) {
        cap = capacity;
        kv.clear();
        ki.clear();
    }
    
    int get(int key) {
        if (ki.find(key) == ki.end()) {
            return -1;
        }
        int result = kv[ki[key]].second;
        kv.erase(kv.begin() + ki[key]);
        for (int i = ki[key]; i < (int) kv.size(); i++) {
            ki[kv[i].first]--;
        }
        ki[key] = kv.size();
        kv.push_back({key, result});
        return result;
    }
    
    void put(int key, int value) {
        if (ki.find(key) != ki.end()) {
            kv.erase(kv.begin() + ki[key]);
            for (int i = ki[key]; i < (int) kv.size(); i++) {
                ki[kv[i].first]--;
            }
            ki[key] = kv.size();
            kv.push_back({key, value});
        } else {
            if ((int) kv.size() == cap) {
                ki.erase(kv[0].first);
                kv.erase(kv.begin());
                for (int i = 0; i < (int) kv.size(); i++) {
                    ki[kv[i].first]--;
                }
            }
            ki[key] = kv.size();
            kv.push_back({key, value});
        }
    }

private:
    vector<pair<int, int>> kv;
    unordered_map<int, int> ki;
    int cap;
};
