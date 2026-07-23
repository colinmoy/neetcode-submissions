class Solution {
public:
    bool isValid(string s) {
        stack<char> stack;
        for (char c : s) {
            if (c == '(' || c == '{' || c == '[') {
                stack.push(c);
            } else {
                if (stack.empty()) {
                    return false;
                } else if (stack.top() == '(' && c == ')') {
                    stack.pop();
                } else if (stack.top() == '{' && c == '}') {
                    stack.pop();
                } else if (stack.top() == '[' && c == ']') {
                    stack.pop();
                } else {
                    return false;
                }
            }
        }
        return stack.empty();
    }
};
