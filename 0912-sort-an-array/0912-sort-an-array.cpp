class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        int m = nums[0];
        int M = nums[0];
        for (int i = 0; i < nums.size(); i++) {
            m = min(m, nums[i]);
            M = max(M, nums[i]);
        }
        if (m == M) {
            return nums;
        }
        // filling count array
        int range = M - m + 1;
        vector<int> count(range);
        for (int i = 0; i < nums.size(); i++) {
            count[nums[i] - m]++;
        }
        // now rewriting nums
        int k = 0;
        for (int i = 0; i < range; i++) {
            while (count[i]-- > 0) {
                nums[k++] = i + m;
            }
        }
        return nums;
    }
};