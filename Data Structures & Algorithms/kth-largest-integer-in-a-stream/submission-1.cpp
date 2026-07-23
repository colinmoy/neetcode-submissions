class KthLargest {
public:
    KthLargest(int k, vector<int>& nums) {
        kk = k;
        arr = vector<int>(nums);
        sort(arr.begin(), arr.end(), greater<int>());
        for (int i = (int) arr.size() - 1; i >= k; i--) {
            arr.erase(arr.begin() + i);
        }
    }
    
    int add(int val) {
        int ind = (int) arr.size() - 1;
        while (ind >= 0 && val > arr[ind]) {
            ind--;
        }
        ind++;
        arr.insert(arr.begin() + ind, val);
        if (arr.size() > kk) {
            arr.pop_back();
        }
        return arr[kk-1];
    }

private:
    vector<int> arr;
    int kk;
};
