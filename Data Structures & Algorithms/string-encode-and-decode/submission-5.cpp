class Solution {
public:

    string encode(vector<string>& strs) {
        string result = "";
        for (string s : strs) {
            int sz = s.size();
            string l = to_string(sz);
            int szlen = 1;
            while (sz >= 10) {
                sz /= 10;
                szlen++;
            }
            result += to_string(szlen);
            result += l;
            result += s;
        }
        cout << "encoded " << result << endl;
        return result;
    }

    vector<string> decode(string s) {
        vector<string> result;
        int ind = 0;
        while (ind < s.size()) {
            int szlen = stoi(s.substr(ind, 1));
            ind++;
            int l = stoi(s.substr(ind, szlen));
            ind += szlen;
            string temp = s.substr(ind, l);
            ind += l;
            result.push_back(temp);
            cout << "pushed back " << temp << endl;
        }
        return result;
    }
};
