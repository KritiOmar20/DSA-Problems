class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        long long count = 0;
        for(int i = 0;i < n;i++){
            int low = i + 1;
            int high = n - 1;
            int rem = lower - nums[i];
            int ans = n;
            while(low <= high){
                int mid = (low + high) / 2;
                if(nums[mid] >= rem){
                    ans = mid;
                    high = mid - 1;
                }
                else low = mid + 1;
            }
            low = i + 1;
            high = n - 1;
            rem = upper - nums[i];
            int cnt = n;
            while(low <= high){
                int mid = (low + high) / 2;
                if(nums[mid] > rem){
                    cnt = mid;
                    high = mid - 1;
                }
                else low = mid + 1;
            }
            count += (cnt - ans);
        }
        return count;
    }
};