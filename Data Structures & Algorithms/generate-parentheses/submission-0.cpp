class Solution {
public:
    vector<string> generateParenthesis(int n) {
        queue<string> strings;
        queue<stack<char>> stacks;
        queue<int> nums;
        strings.push("");
        stacks.push(stack<char>());
        nums.push(0);
        vector<string> result;
        while (!strings.empty()) {
            string s = strings.front();
            strings.pop();
            stack<char> st = stacks.front();
            stacks.pop();
            int num = nums.front();
            nums.pop();
            if (num == n) {
                if (st.empty()) {
                    result.push_back(s);
                } else {
                    s += ")";
                    st.pop();
                    strings.push(s);
                    stacks.push(st);
                    nums.push(num);
                }
            } else {
                string temps = s;
                stack<char> tempst(st);
                int tempnum = num;
                temps += "(";
                tempst.push('(');
                tempnum++;
                strings.push(temps);
                stacks.push(tempst);
                nums.push(tempnum);
                if (!st.empty()) {
                    temps = s;
                    temps += ")";
                    tempst.pop();
                    tempst.pop();
                    tempnum = num;
                    strings.push(temps);
                    stacks.push(tempst);
                    nums.push(tempnum);
                }
            }
        }
        return result;
    }
};
