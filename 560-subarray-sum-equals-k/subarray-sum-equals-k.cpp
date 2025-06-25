class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
       unordered_map<int, int> prefix;
        int currSum = 0, count = 0;
        prefix[0] = 1;
        for (int num : nums) {
            currSum += num;
            if (prefix.find(currSum - k) != prefix.end()) {
                count += prefix[currSum - k];
            }

            prefix[currSum]++;
        }

        return count;
    }
};