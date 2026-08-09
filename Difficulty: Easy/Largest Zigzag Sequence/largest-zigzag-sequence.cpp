class Solution {
public:
    int zigzagSequence(vector<vector<int>>& mat) {
        int n = mat.size();
        vector<int> dp(n);
        for (int j = 0; j < n; j++)
            dp[j] = mat[0][j];

        for (int i = 1; i < n; i++) {
            int maxi1 = -1, maxi2 = -1, idx = -1;

            for (int j = 0; j < n; j++) {
                if (dp[j] > maxi1) {
                    maxi2 = maxi1;
                    maxi1 = dp[j];
                    idx = j;
                } else if (dp[j] > maxi2) {
                    maxi2 = dp[j];
                }
            }

            vector<int> next(n);
            for (int j = 0; j < n; j++) {
                if (j == idx)
                    next[j] = mat[i][j] + maxi2;
                else
                    next[j] = mat[i][j] + maxi1;
            }
            dp = next;
        }

        return *max_element(dp.begin(), dp.end());
    }
};