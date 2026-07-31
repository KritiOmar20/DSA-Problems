class Solution {
public:
    static const int MOD = 1000000007;

    int countSubsets(vector<int>& arr) {
        vector<int> freq(31, 0);
        for (int x : arr)
            freq[x]++;
        vector<int> primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
        vector<int> mask(31, -1);

        for (int x = 2; x <= 30; x++) {
            int m = 0;
            bool valid = true;

            for (int i = 0; i < 10; i++) {
                int p = primes[i];

                if (x % (p * p) == 0) {
                    valid = false;
                    break;
                }

                if (x % p == 0)
                    m |= (1 << i);
            }

            if (valid)
                mask[x] = m;
        }

        vector<long long> dp(1 << 10, 0);
        dp[0] = 1;

        for (int num = 2; num <= 30; num++) {
            if (freq[num] == 0 || mask[num] == -1)
                continue;

            vector<long long> newDp = dp;
            int curMask = mask[num];

            for (int oldMask = 0; oldMask < (1 << 10); oldMask++) {
                if ((oldMask & curMask) == 0) {
                    int newMask = oldMask | curMask;
                    newDp[newMask] =
                        (newDp[newMask] + dp[oldMask] * freq[num]) % MOD;
                }
            }
            dp = newDp;
        }

        long long ans = 0;
        for (int m = 1; m < (1 << 10); m++)
            ans = (ans + dp[m]) % MOD;
        long long ways = 1;
        for (int i = 0; i < freq[1]; i++)
            ways = (ways * 2) % MOD;

        ans = (ans * ways) % MOD;

        return (int)ans;
    }
};