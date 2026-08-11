class Solution {
public:
    vector<int> largestSquare(vector<vector<int>>& mat,
                               vector<vector<int>>& queries,
                               int k) {
        
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> pref(n + 1, vector<int>(m + 1, 0));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                pref[i + 1][j + 1] =
                    mat[i][j]
                    + pref[i][j + 1]
                    + pref[i + 1][j]
                    - pref[i][j];
            }
        }

        auto getSum = [&](int r1, int c1, int r2, int c2) {
            return pref[r2 + 1][c2 + 1]
                 - pref[r1][c2 + 1]
                 - pref[r2 + 1][c1]
                 + pref[r1][c1];
        };

        vector<int> ans;

        for (auto &q : queries) {
            int i = q[0];
            int j = q[1];

            int maxRadius = min({
                i,
                j,
                n - 1 - i,
                m - 1 - j
            });

            int low = 0;
            int high = maxRadius;
            int best = -1;

            while (low <= high) {
                int radius = low + (high - low) / 2;
                int r1 = i - radius;
                int c1 = j - radius;
                int r2 = i + radius;
                int c2 = j + radius;

                int ones = getSum(r1, c1, r2, c2);

                if (ones <= k) {
                    best = radius;
                    low = radius + 1;
                }
                else {
                    high = radius - 1;
                }
            }
            if (best == -1)
                ans.push_back(-1);
            else
                ans.push_back(2 * best + 1);
        }

        return ans;
    }
};