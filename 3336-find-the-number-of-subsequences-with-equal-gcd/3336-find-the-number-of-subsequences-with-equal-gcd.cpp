class Solution {
public:
    static const int MOD = 1e9+7;
    int n;
    int dp[201][201][201];
    int solve(int ind, int g1, int g2, vector<int>&nums){
        if(ind == n){
            return(g1 != 0 && g1 ==g2 );  
        }
        int &res = dp[ind][g1][g2];
        if(res != -1) return res;
        res=0;
        res = solve(ind+1,g1,g1,nums);
        // Ignore current element
        res = solve(ind + 1, g1, g2, nums);

        // Put in first seq
        int ng1 = (g1 == 0) ? nums[ind] : gcd(g1, nums[ind]);
        res = (res + solve(ind + 1, ng1, g2, nums)) % MOD;

        // Put in second seq
        int ng2 = (g2 == 0) ? nums[ind] : gcd(g2, nums[ind]);
        res = (res + solve(ind + 1, g1, ng2, nums)) % MOD;
        return res;
    }
    int subsequencePairCount(vector<int>& nums) {
        n= nums.size();
        memset(dp,-1,sizeof(dp));
        return solve(0,0,0,nums);
    }
};