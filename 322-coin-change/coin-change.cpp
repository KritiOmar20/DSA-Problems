class Solution {
public:
    int solve(int ind, vector<int>& coins, int amt, vector<vector<int>>& dp) {
    if (amt == 0) return 0;
    if (ind == coins.size()) return 1e9;
    
    if (dp[ind][amt] != -1) return dp[ind][amt];

    int take = 1e9;
    if (amt >= coins[ind]) {
        take = 1 + solve(ind, coins, amt - coins[ind], dp);
    }
    int notTake = solve(ind + 1, coins, amt, dp);

    return dp[ind][amt] = min(take, notTake);
}

    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
        int ans = solve(0, coins, amount, dp);
        return ans >= 1e9 ? -1 : ans;
    }

};