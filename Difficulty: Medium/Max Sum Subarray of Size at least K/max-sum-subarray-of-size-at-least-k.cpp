class Solution {
public:
    int maxSumWithK(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> maxEnd(n);
        maxEnd[0] = arr[0];

        for (int i = 1; i < n; i++) {
            maxEnd[i] = max(arr[i], maxEnd[i - 1] + arr[i]);
        }

        int currSum = 0;
        for (int i = 0; i < k; i++)
            currSum += arr[i];

        int ans = currSum;
        for (int i = k; i < n; i++) {
            currSum += arr[i] - arr[i - k];
            ans = max(ans, currSum);
            ans = max(ans, currSum + maxEnd[i - k]);
        }
        return ans;
    }
};