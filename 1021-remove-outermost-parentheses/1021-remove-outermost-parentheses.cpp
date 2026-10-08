class Solution {
public:
    string removeOuterParentheses(string s) {
        string res;
        stack<char> st;
        for (auto ch : s) {
            if (ch == ')') {
                st.pop();
            }
            if (!st.empty()) {
                res.push_back(ch);
            }
            if (ch == '(') {
                st.emplace(ch);
            }
        }
        return res;
    }
};