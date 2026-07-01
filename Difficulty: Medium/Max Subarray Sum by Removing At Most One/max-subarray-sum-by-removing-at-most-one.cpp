class Solution {
public:
    int maxSumSubarray(vector<int>& arr) {
        int keep = arr[0];
        int drop = INT_MIN;
        int ans = arr[0];

        for (int i = 1; i < arr.size(); i++) {
            int newDrop = max(drop == INT_MIN ? INT_MIN : drop + arr[i], keep);
            int newKeep = max(keep + arr[i], arr[i]);
            keep = newKeep;
            drop = newDrop;
            ans = max(ans, max(keep, drop));
        }

        return ans;
    }
};