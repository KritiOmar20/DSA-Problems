
class Solution {
public:
   
    int binarySearchClosest(vector<int>& arr, int target, int n) {
        int left = 0, right = n - 1;
        int best = arr[0];

        while (left <= right) {
            int mid = (left + right) / 2;
            if (abs(arr[mid] - target) < abs(best - target)) {
                best = arr[mid];
            }
            if (arr[mid] == target) {
                return arr[mid]; 
            } else if (arr[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return best;
    }

    int minAbsoluteSumDiff(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int mod = 1e9 + 7;

        vector<int> sorted_nums1 = nums1;
        sort(sorted_nums1.begin(), sorted_nums1.end());

        long long totalSum = 0;
        int maxReduction = 0;

        for (int i = 0; i < n; i++) {
            totalSum += abs(nums1[i] - nums2[i]);
        }
        for (int i = 0; i < n; i++) {
            int a = nums1[i], b = nums2[i];
            int currDiff = abs(a - b);
            int closest = binarySearchClosest(sorted_nums1, b, n);
            int newDiff = abs(closest - b);
            int reduction = currDiff - newDiff;
            maxReduction = max(maxReduction, reduction);
        }
        return (totalSum - maxReduction + mod) % mod;
    }
};

