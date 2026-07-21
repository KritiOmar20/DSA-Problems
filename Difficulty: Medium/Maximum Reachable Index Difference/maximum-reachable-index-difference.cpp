#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxIndexDifference(string s) {
        int n = s.size();
        vector<int> bestEnd(26, -1);
        int ans = -1;
        for (int i = n - 1; i >= 0; --i) {
            int c = s[i] - 'a';
            int far = i;
            // If next character exists on the right
            if (c < 25 && bestEnd[c + 1] != -1) {
                far = bestEnd[c + 1];
            }
            // Update best reachable end for this character
            bestEnd[c] = max(bestEnd[c], far);
            // Valid starting positions are only 'a'
            if (c == 0) {
                ans = max(ans, far - i);
            }
        }
        return ans;
    }
};