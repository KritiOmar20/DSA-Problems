class Solution {
  public:
    int maxTask(vector<int>& h, vector<int>& l) {
        // code here
        int n = h.size();
        vector<int> dp(n + 1, 0);
        dp[1] = max(h[0], l[0]);
        for (int i = 2; i <= n; i++) {
            dp[i] = max(dp[i - 1] + l[i - 1],
                        dp[i - 2] + h[i - 1]);
        }
        return dp[n];
    }
};