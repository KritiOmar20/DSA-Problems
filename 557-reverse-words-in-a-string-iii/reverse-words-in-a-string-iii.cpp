class Solution {
public:
    void reverse(vector<char> &x, int left, int right) {
        while (left < right) {
            swap(x[left++], x[right--]);
        }
    }

    string reverseWords(string s) {
        vector<char> ans(s.begin(), s.end());
        int l = 0;
        for (int r = 0; r < ans.size(); r++) {
            if (ans[r] == ' ') {
                reverse(ans, l, r - 1);
                l = r + 1;
            } else if (r == ans.size() - 1) {
                reverse(ans, l, r);
                l = r + 1;
            }
        }
        return string(ans.begin(), ans.end());
    }
};