class Solution {
public:
    int longestValidParentheses(string s) {
        int left = 0, right = 0, maxLen = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') left++;
            else right++;
            
            if (left == right) {
                maxLen = max(maxLen, left * 2);
            } else if (right > left) {
                left = 0;
                right = 0;
            }
        }
        // Reset left and right for Right to Left Traversal
        left = 0, right = 0;
        // Right to Left Traversal (to handle unbalanced cases like "(()")
        for (int i = s.length() - 1; i >= 0; i--) {
            if (s[i] == ')') right++;
            else left++;
            if (left == right) {
                maxLen = max(maxLen, left * 2);
            } else if (left > right) {
                left = 0;
                right = 0;
            }
        }
        return maxLen;
    }
};