class MinStack {
public:
    MinStack() {
        arr.clear();
    }
    
    void push(int val) {
        arr.push_back(val);
    }
    
    void pop() {
        arr.pop_back();
    }
    
    int top() {
        return arr[arr.size() - 1];
    }
    
    int getMin() {
        int result = arr[0];
        for (int a : arr) {
            result = min(result, a);
        }
        return result;
    }

private:
    vector<int> arr;
};
