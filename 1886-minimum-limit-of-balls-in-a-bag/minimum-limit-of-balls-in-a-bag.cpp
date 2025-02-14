class Solution {
public:
    bool isPossible(vector<int>& nums, int maxAllow, int maxOperations) {
        int op = 0;  
        for (int num : nums) {
            if (num > maxAllow) {
                op += (num - 1) / maxAllow;  // Equivalent to ceil(num / maxAllow) - 1
            }
            if (op > maxOperations) {
                return false;
            }
        }
        return true;
    }

    int minimumSize(vector<int>& nums, int maxOperations) {
        int right = *max_element(nums.begin(), nums.end()); // Maximum value in array
        int left = 1, res = right;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (isPossible(nums, mid, maxOperations)) { 
                res = mid;  // Store the minimum found so far
                right = mid - 1; // Search in smaller sizes
            } else {
                left = mid + 1; // Increase allowed size
            }
        }
        return res;
    }
};