class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<string> s;
        for (string t : tokens) {
            if (t == "+" || t == "-" || t == "*" || t == "/") {
                int y = stoi(s.top());
                s.pop();
                int x = stoi(s.top());
                s.pop();
                if (t == "+") {
                    s.push(to_string(x + y));
                } else if (t == "-") {
                    s.push(to_string(x - y));
                } else if (t == "*") {
                    s.push(to_string(x * y));
                } else {
                    s.push(to_string(x / y));
                }
            } else {
                s.push(t);
            }
        }
        return stoi(s.top());
    }
};
