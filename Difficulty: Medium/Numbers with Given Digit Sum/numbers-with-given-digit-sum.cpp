class Solution {
  public:
    int countWays(int n, int sum) {
        // code here
        if (sum < 1 || sum > 9 * n)
            return -1;
        vector<vector<long long>> dp(n + 1, vector<long long>(sum + 1, 0));
        // First digit (1 to 9)
        for (int d = 1; d <= 9 && d <= sum; d++)
            dp[1][d] = 1;
        // Remaining digits
        for (int i = 2; i <= n; i++) {
            for (int s = 0; s <= sum; s++) {
                for (int d = 0; d <= 9 && d <= s; d++) {
                    dp[i][s] += dp[i - 1][s - d];
                }
            }
        }
        return dp[n][sum] == 0 ? -1 : dp[n][sum];
    }
};