class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result({});
        map<string, int> map;
        int ind = 0;
        for (string str : strs) {
            string s = str;
            std::sort(s.begin(), s.end());
            if (map.find(s) == map.end()) {
                map.insert({s, ind});
                result.push_back({str});
                ind++;
            } else {
                result[map[s]].push_back(str);
            }
        }
        return result;
    }
};
