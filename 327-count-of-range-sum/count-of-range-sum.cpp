class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        multiset<long> prefix;
        prefix.insert(0);
        long sum = 0;
        int count = 0;
        for (int i = 0; i < nums.size(); ++i) {
            sum += nums[i];
            auto low = prefix.lower_bound(sum - upper);
            auto high = prefix.upper_bound(sum - lower);

            count += distance(low, high);
            prefix.insert(sum);
        }
        return count;
    }
};