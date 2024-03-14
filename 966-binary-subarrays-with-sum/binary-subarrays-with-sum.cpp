class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map<int, int> cnt;
        cnt[0] = 1;
        int sum = 0;
        int subarrays = 0;

        for (int num : nums) {
            sum += num;
            if (cnt.find(sum - goal) != cnt.end()) {
                subarrays += cnt[sum - goal];
            }
            cnt[sum]++;
        }

        return subarrays;
    }
};